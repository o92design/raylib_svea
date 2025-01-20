#include "game_loop.h"
#include "game_render.h"
#include <stdio.h>
#include <stdbool.h>

#include "game_initialize.h"
#include "systems/sprite_loader_system.h"
#include "systems/entity_component_system.h"

// Function to run the game loop
int run_game_loop(void) {
    EntityComponentManager* entityComponentManagerPtr = create_component_manager();
    size_t entityId = create_entity(entityComponentManagerPtr);
    size_t entityIdTwo = create_entity(entityComponentManagerPtr);

    // Load Sprite
    SpriteComponent spriteComponent = load_sprite("res/img/viking.png");
    COMPONENT_ID componentId = add_sprite_component(entityComponentManagerPtr, spriteComponent);
    entityComponentManagerPtr->spriteMap[entityId].componentId = componentId;
    entityComponentManagerPtr->spriteMap[entityIdTwo].componentId = componentId;

    SpriteComponent spriteComponentTwo = load_sprite("res/img/canon.png");
    COMPONENT_ID componentIdTwo = add_sprite_component(entityComponentManagerPtr, spriteComponentTwo);
    entityComponentManagerPtr->spriteMap[entityIdTwo].componentId = componentIdTwo;

    // Create Position Component
    PositionComponent positionComponent = {-1, 20, 200};
    COMPONENT_ID positionComponentId = add_position_component(entityComponentManagerPtr, positionComponent);
    entityComponentManagerPtr->positionMap[entityId].componentId = positionComponentId;

    PositionComponent positionComponentTwo = {-1, 0, 0};
    COMPONENT_ID positionComponentIdTwo = add_position_component(entityComponentManagerPtr, positionComponentTwo);
    entityComponentManagerPtr->positionMap[entityIdTwo].componentId = positionComponentIdTwo;

    while (!WindowShouldClose()) {
        // Update Game Logic here

        render_game(entityComponentManagerPtr);
    }

    destroy_component_manager(&entityComponentManagerPtr);
    return 0; // Return 0 to indicate success
}