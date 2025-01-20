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
    COMPONENT_ID spriteId = add_sprite_component(entityComponentManagerPtr, spriteComponent);
    entityComponentManagerPtr->componentMaps[entityId].componentIds[COMPONENT_TYPE_SPRITE] = spriteId;

    SpriteComponent spriteComponentTwo = load_sprite("res/img/canon.png");
    COMPONENT_ID spriteIdTwo = add_sprite_component(entityComponentManagerPtr, spriteComponentTwo);
    entityComponentManagerPtr->componentMaps[entityIdTwo].componentIds[COMPONENT_TYPE_SPRITE] = spriteIdTwo;

    // Create Position Component
    PositionComponent positionComponent = {-1, 20, 200};
    COMPONENT_ID posId = add_position_component(entityComponentManagerPtr, positionComponent);
    entityComponentManagerPtr->componentMaps[entityId].componentIds[COMPONENT_TYPE_POSITION] = posId;

    PositionComponent positionComponentTwo = {-1, 0, 0};
    COMPONENT_ID posIdTwo = add_position_component(entityComponentManagerPtr, positionComponentTwo);
    entityComponentManagerPtr->componentMaps[entityIdTwo].componentIds[COMPONENT_TYPE_POSITION] = posIdTwo;

    while (!WindowShouldClose()) {
        render_game(entityComponentManagerPtr);
    }

    destroy_component_manager(&entityComponentManagerPtr);
    return 0;
}