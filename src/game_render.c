#include "game_render.h"
#include "raylib.h"
#include "systems/render_system.h"
#include "systems/entity_component_system.h"
#include "component_handler.h"

void render_game(EntityComponentManager* p_entityComponentManagerPtr) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for(size_t entityIndex = 0; entityIndex < p_entityComponentManagerPtr->entityCount; entityIndex++) {
        size_t entityId = p_entityComponentManagerPtr->entities[entityIndex].id;
        
        // Get component IDs
        COMPONENT_ID spriteComponentId = retrieve_entity_component(p_entityComponentManagerPtr, 
                                                                 entityId, 
                                                                 COMPONENT_TYPE_SPRITE);
        COMPONENT_ID positionComponentId = retrieve_entity_component(p_entityComponentManagerPtr, 
                                                                   entityId, 
                                                                   COMPONENT_TYPE_POSITION);

        // Get actual components using component handler
        SpriteComponent* spriteComponentPtr = get_component(p_entityComponentManagerPtr, 
                                                          COMPONENT_TYPE_SPRITE, 
                                                          spriteComponentId);
        PositionComponent* positionComponentPtr = get_component(p_entityComponentManagerPtr, 
                                                              COMPONENT_TYPE_POSITION, 
                                                              positionComponentId);

        if (spriteComponentPtr && positionComponentPtr) {
            render_system(spriteComponentPtr, positionComponentPtr);
        }
    }

    EndDrawing();
}