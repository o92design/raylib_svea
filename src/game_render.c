#include "game_render.h"
#include "raylib.h"
#include "systems/render_system.h"

#include <stdio.h>

// Function to render the game
void render_game(EntityComponentManager* p_entityComponentManagerPtr) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for(size_t entityIndex = 0; entityIndex < p_entityComponentManagerPtr->entityCount; entityIndex++) {
        size_t entityId = p_entityComponentManagerPtr->entities[entityIndex].id;
        COMPONENT_ID spriteComponentId = retrieve_entity_component(p_entityComponentManagerPtr, entityId, COMPONENT_TYPE_SPRITE);
        SpriteComponent* spriteComponentPtr = p_entityComponentManagerPtr->components.spriteComponents[spriteComponentId];

        COMPONENT_ID positionComponentId = retrieve_entity_component(p_entityComponentManagerPtr, entityId, COMPONENT_TYPE_POSITION);
        PositionComponent* positionComponentPtr = p_entityComponentManagerPtr->components.positionComponents[positionComponentId];

        render_system(spriteComponentPtr, positionComponentPtr);
    }

    EndDrawing();
}