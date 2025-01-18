#include "game_initialize.h"
#include "game_loop.h"

int main(void) {
    // Initialize the game
    /** 
    if (initialize_game() != 0) {
        return -1; // Initialization failed
    }
    /**/

    // Run the game loop
    if (run_game_loop() != 0) {
        return -1; // Game loop failed
    }

    return 0;
}