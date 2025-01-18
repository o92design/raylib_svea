# Compiler and linker
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -Llib -lraylib

# Directories
SRC_DIR = src
OBJ_DIR = build
INCLUDE_DIR = include
LIB_DIR = lib

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/**/*.c)
DEBUG_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/Debug/%.o)
RELEASE_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/Release/%.o)

# Target executables
DEBUG_TARGET = build/Debug/raylib_svea
RELEASE_TARGET = build/Release/raylib_svea

# Default target
all: debug release

# Debug build
debug: CFLAGS += -g
debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(DEBUG_OBJS)
    $(CC) $(DEBUG_OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/Debug/%.o: $(SRC_DIR)/%.c
    @mkdir -p $(dir $@)
    $(CC) $(CFLAGS) -c $< -o $@

# Release build
release: CFLAGS += -O2
release: $(RELEASE_TARGET)

$(RELEASE_TARGET): $(RELEASE_OBJS)
    $(CC) $(RELEASE_OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/Release/%.o: $(SRC_DIR)/%.c
    @mkdir -p $(dir $@)
    $(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
    rm -rf $(OBJ_DIR) build/Debug build/Release

# Run the game
run: $(DEBUG_TARGET)
    ./$(DEBUG_TARGET)

.PHONY: all clean run debug release