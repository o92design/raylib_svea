# Compiler and linker
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Ilib
LDFLAGS = -Llib -lraylib -lcunit

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

# Source and object files
SRCS = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c))
DEBUG_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/Debug/%.o)
RELEASE_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/Release/%.o)
TEST_SRCS = $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_OBJS = $(TEST_SRCS:$(TEST_SRC_DIR)/%.c=$(OBJ_DIR)/Tests/%.o)
TEST_OBJS += $(filter-out $(OBJ_DIR)/Debug/main.o, $(DEBUG_OBJS))  # Include debug objects in test build, excluding main.o

# Target executables
DEBUG_TARGET = build/Debug/raylib_svea
RELEASE_TARGET = build/Release/raylib_svea
TEST_TARGET = build/Tests/test_runner

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
tests: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(TEST_OBJS) -o $@ $(LDFLAGS) $(LIB_LINKS)

$(OBJ_DIR)/Tests/%.o: $(TEST_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) build/Debug build/Release build/Tests

# Run the game
run: $(DEBUG_TARGET)
	./$(DEBUG_TARGET)

# Run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: all clean run debug release tests test