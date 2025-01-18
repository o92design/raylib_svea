#include "game_initialize.h"
#include "game_loop.h"
#include <stdio.h>

int main(void) {
    // Initialize the game
    if (initialize_game() != 0) {
        fprintf(stderr, "Error: Could not initialize game.\n");
        return -1; // Initialization failed
    }

    // Run the game loop
    if (run_game_loop() != 0) {
        fprintf(stderr, "Error: Game loop failed.\n");
        return -1; // Game loop failed
    }

    if(cleanup_game() == -1) {
        fprintf(stderr, "Error: Could not cleanup game properly.\n");
        return -1; // Cleanup failed
    }

    return 0;
}