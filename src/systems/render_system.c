#include "systems/render_system.h"
#include "systems/entity_component_system.h"

#include "raylib.h"

#include <stdio.h>

// Function to render all entities
void render_system(SpriteComponent* p_spriteComponentsPtr, PositionComponent* p_positionComponentsPtr) {
    DrawTexture(p_spriteComponentsPtr->sprite, p_positionComponentsPtr->positionX, p_positionComponentsPtr->positionY, WHITE);
}