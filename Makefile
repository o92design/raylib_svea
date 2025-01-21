# Compiler and linker
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude -Ilib -I$(TEST_DIR)
LDFLAGS = -Llib -lraylib -lcunit -lGL -lm -lpthread -ldl -lrt -lX11

# Compiler and linker for Windows
CC_WIN = x86_64-w64-mingw32-gcc
# Update Windows flags to include CUnit
CFLAGS_WIN = -Wall -Wextra -g -Iinclude -Ilib -I$(TEST_DIR)
LDFLAGS_WIN = -Llib -Llib/windows/raylib-5.5/lib -lcunit -lraylib -lgdi32 -lwinmm -lopengl32 -lm -lpthread

# Include all libraries in lib/ directory, excluding .md files
LIBS = $(filter-out %.md, $(wildcard lib/*))
LIB_INCLUDES = $(foreach lib, $(LIBS), -I$(lib)/include)
LIB_LINKS = $(foreach lib, $(LIBS), -L$(lib)/lib -lraylib)

# Directories
SRC_DIR = src
OBJ_DIR = build
INCLUDE_DIR = include
TEST_DIR = tests
TEST_SRC_DIR = $(TEST_DIR)/src
TEST_INCLUDE_DIR = $(TEST_DIR)/include

# Source and object files
SRCS = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c))
DEBUG_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/Debug/%.o)
RELEASE_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/Release/%.o)
TEST_SRCS = $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_OBJS = $(TEST_SRCS:$(TEST_SRC_DIR)/%.c=$(OBJ_DIR)/Tests/%.o)
TEST_OBJS += $(filter-out $(OBJ_DIR)/Debug/main.o, $(DEBUG_OBJS))  # Include debug objects in test build, excluding main.o

# Source and object files for Windows
DEBUG_OBJS_WIN = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/Debug/Windows/%.o)
RELEASE_OBJS_WIN = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/Release/Windows/%.o)
TEST_OBJS_WIN = $(TEST_SRCS:$(TEST_SRC_DIR)/%.c=$(OBJ_DIR)/Tests/Windows/%.o)
TEST_OBJS_WIN += $(filter-out $(OBJ_DIR)/Debug/Windows/main.o, $(DEBUG_OBJS_WIN))  # Include debug objects in test build, excluding main.o

# Target executables
DEBUG_TARGET = build/Debug/raylib_svea
RELEASE_TARGET = build/Release/raylib_svea
TEST_TARGET = build/Tests/test_runner

# Target executables for Windows
DEBUG_TARGET_WIN = build/Debug/Windows/raylib_svea.exe
RELEASE_TARGET_WIN = build/Release/Windows/raylib_svea.exe
TEST_TARGET_WIN = build/Tests/Windows/test_runner.exe

# Default target
all: debug release

# Debug build
debug: CFLAGS += -g $(LIB_INCLUDES)
debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(DEBUG_OBJS) $(OBJ_DIR)/Debug/main.o
	@mkdir -p $(dir $@)
	$(CC) $(DEBUG_OBJS) $(OBJ_DIR)/Debug/main.o -o $@ $(LDFLAGS) $(LIB_LINKS)

$(OBJ_DIR)/Debug/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Release build
release: CFLAGS += -O2 $(LIB_INCLUDES)
release: $(RELEASE_TARGET)

$(RELEASE_TARGET): $(RELEASE_OBJS) $(OBJ_DIR)/Release/main.o
	@mkdir -p $(dir $@)
	$(CC) $(RELEASE_OBJS) $(OBJ_DIR)/Release/main.o -o $@ $(LDFLAGS) $(LIB_LINKS)

$(OBJ_DIR)/Release/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Test build
tests: CFLAGS += -g $(LIB_INCLUDES)
tests: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(TEST_OBJS) -o $@ $(LDFLAGS) $(LIB_LINKS)

$(OBJ_DIR)/Tests/%.o: $(TEST_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# CI build
ci-build: CFLAGS += -O2 $(LIB_INCLUDES)
ci-build: $(RELEASE_TARGET)

# CI test
ci-test: CFLAGS += -g $(LIB_INCLUDES)
ci-test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) build/Debug build/Release build/Tests

# Run the game
run: $(DEBUG_TARGET)
	./$(DEBUG_TARGET)

# Run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Debug build for Windows
debug-windows: CFLAGS_WIN += -g $(LIB_INCLUDES)
debug-windows: $(DEBUG_TARGET_WIN)

$(DEBUG_TARGET_WIN): $(DEBUG_OBJS_WIN) $(OBJ_DIR)/Debug/Windows/main.o
	@mkdir -p $(dir $@)
	$(CC_WIN) $(DEBUG_OBJS_WIN) $(OBJ_DIR)/Debug/Windows/main.o -o $@ $(LDFLAGS_WIN)

$(OBJ_DIR)/Debug/Windows/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC_WIN) $(CFLAGS_WIN) -c $< -o $@

# Update tests-windows to depend on CUnit
tests-windows: CFLAGS_WIN += -g $(LIB_INCLUDES)
tests-windows: $(TEST_TARGET_WIN)

$(TEST_TARGET_WIN): $(TEST_OBJS_WIN)
	@mkdir -p $(dir $@)
	$(CC_WIN) $(TEST_OBJS_WIN) -o $@ $(LDFLAGS_WIN)

$(OBJ_DIR)/Tests/Windows/%.o: $(TEST_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC_WIN) $(CFLAGS_WIN) -c $< -o $@


run-windows: $(DEBUG_TARGET_WIN)
	./$(DEBUG_TARGET_WIN)

test-windows: $(TEST_TARGET_WIN)
	./$(TEST_TARGET_WIN)

.PHONY: all clean run debug release tests test ci-build ci-test debug-windows tests-windows run-windows test-windows
