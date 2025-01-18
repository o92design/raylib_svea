#include "game_loop.h"
#include <stdio.h>
#include <stdbool.h>

// Function to run the game loop
int run_game_loop(void) {
    bool running = true;

    while (running) {
        // Placeholder for game logic
        printf("Game loop running...\n");

        // Placeholder for user input to exit the loop
        char input;
        printf("Press 'q' to quit: ");
        scanf(" %c", &input);
        if (input == 'q') {
            running = false;
        }
    }

    printf("Game loop exited.\n");
    return 0; // Return 0 to indicate success
}