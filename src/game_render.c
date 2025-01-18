#include "game_render.h"
#include "raylib.h"
#include "systems/render_system.h"


#include <stdio.h>

// Function to render the game
void render_game(void) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    render_system();

    EndDrawing();
}