#include "systems/render_system.h"
#include "components/sprite_component.h"
#include "raylib.h"

#include <stdio.h>

// Function to render all entities
void render_system(void) {
    // Example rendering logic
    // In a real implementation, you would iterate over all entities and render those with a TextureComponent
    SpriteComponent exampleTextureComponent;
    exampleTextureComponent.sprite = LoadTexture("res/img/viking.png");

    DrawTexture(exampleTextureComponent.sprite, 200, 200, WHITE);

    UnloadTexture(exampleTextureComponent.sprite);
}
