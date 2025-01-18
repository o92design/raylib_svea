#include "game_render.h"
#include "raylib.h"
#include "systems/render_system.h"

#include <stdio.h>

// Function to render the game
void render_game(SpriteComponent* p_spriteComponentsPtr, size_t p_count) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    render_system(p_spriteComponentsPtr, p_count);

    EndDrawing();
}