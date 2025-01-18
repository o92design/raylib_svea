#include "game_loop.h"
#include "game_render.h"
#include <stdio.h>
#include <stdbool.h>

#include "game_initialize.h"
#include "systems/sprite_loader_system.h"

// Function to run the game loop
int run_game_loop(void) {
    size_t numberOfSprites = 1;
    SpriteComponent spriteComponents[numberOfSprites];

    // Load Sprite
    spriteComponents[0] = load_sprite("res/img/viking.png");

    while (!WindowShouldClose()) {
        // Update Game Logic here

        render_game(spriteComponents, numberOfSprites);
    }

    // Unload Sprites
    if (spriteComponents[0].sprite.id != 0) {
        fprintf(stdout, "There are still sprites in the system, unload them before closing the game.\n");
        
        if (unload_sprites(spriteComponents, numberOfSprites) != 0) {
            fprintf(stderr, "Error: Could not unload sprites.\n");
            return -1; // Unloading sprites failed
        }
    }

    return 0; // Return 0 to indicate success
}