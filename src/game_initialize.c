#include <stdio.h>

#include "game_initialize.h"
#include "raylib.h"

#include "systems/sprite_loader_system.h"

// Function to initialize the game
int initialize_game(void) {
    // Initialize Raylib
    InitWindow(800, 600, "Svea Rike 2 Clone");
    if (!IsWindowReady()) {
        fprintf(stderr, "Error: Could not initialize window.\n");
        return -1; // Initialization failed
    }

    // Set target FPS
    SetTargetFPS(60);

    return 0; // Return 0 to indicate success
}

int cleanup_game() {
    if(!IsWindowReady()) {
        fprintf(stderr, "Error: Window is not initialized. Therefore couldn't cleanup properly\n");
        return -1;
    }

    CloseWindow();
    return 0;
}