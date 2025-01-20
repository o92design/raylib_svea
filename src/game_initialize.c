#include "game_initialize.h"
#include "raylib.h"
#include "systems/sprite_loader_system.h"
#include <stdio.h>

int initialize_game(void) {
    // Initialize Raylib
    InitWindow(800, 600, "Svea Rike 2 Clone");
    if (!IsWindowReady()) {
        fprintf(stderr, "Error: Could not initialize window.\n");
        return -1;
    }

    SetTargetFPS(60);
    return 0;
}

int cleanup_game(void) {
    // Verify window state
    if (!IsWindowReady()) {
        fprintf(stderr, "Warning: Window already closed\n");
        return 0;
    }

    // Wait for any pending GPU operations
    EndDrawing();  // Add this line to ensure no pending draw operations
    
    // Finally close window
    CloseWindow();
    
    printf("Debug: Window cleanup complete\n");
    return 0;
}