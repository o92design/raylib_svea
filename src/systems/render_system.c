#include "systems/render_system.h"
#include "components/sprite_component.h"
#include "raylib.h"

#include <stdio.h>

// Function to render all entities
void render_system(SpriteComponent *spriteComponents, size_t count) {
    for (int i = 0; i < count; i++) {

        if (spriteComponents[i].sprite.id == 0) {
            fprintf(stderr, "Error: Invalid sprite component.\n");
            continue;
        }

        // Draw the texture at the center of the window
        int windowWidth = GetScreenWidth();
        int windowHeight = GetScreenHeight();
        int textureWidth = spriteComponents[i].sprite.width;
        int textureHeight = spriteComponents[i].sprite.height;
        int posX = (windowWidth - textureWidth) / 2;
        int posY = (windowHeight - textureHeight) / 2;

        // Draw a rectangle with a background color behind the texture
        DrawRectangle(posX, posY, textureWidth, textureHeight, RAYWHITE);

        // Draw the texture
        DrawTexture(spriteComponents[i].sprite, posX, posY, WHITE);
    }
}