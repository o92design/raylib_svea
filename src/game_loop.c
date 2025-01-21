#include "game_loop.h"
#include "game_render.h"
#include <stdio.h>
#include <stdbool.h>

#include "game_initialize.h"
#include "systems/sprite_loader_system.h"
#include "systems/entity_component_system.h"

// Add to struct or global state
static GAME_PHASE currentPhase = PHASE_PREPARATION;

bool is_preparation_complete(void) {
    fprintf(stdout, "Preparation complete\n");
    return true;
}

bool is_battle_complete(void) {
    fprintf(stdout, "Battle complete\n");
    return true;
}

bool is_result_complete(void) {
    fprintf(stdout, "Result complete\n");
    return true;
}

bool is_post_battle_complete(void) {
    fprintf(stdout, "Post battle complete\n");
    return true;
}

void handle_phase_transition(void) {
    switch(currentPhase) {
        case PHASE_PREPARATION:
            if (is_preparation_complete()) {
                fprintf(stdout, "Switching to battle phase\n");
                currentPhase = PHASE_BATTLE;
            }
            break;
        case PHASE_BATTLE:
            if (is_battle_complete()) {
                fprintf(stdout, "Switching to result phase\n");
                currentPhase = PHASE_RESULT;
            }
            break;
        case PHASE_RESULT:
            if (is_result_complete()) {
                fprintf(stdout, "Switching to post battle phase\n");
                currentPhase = PHASE_POST_BATTLE;
            }
            break;
        case PHASE_POST_BATTLE:
            if (is_post_battle_complete()) {
                fprintf(stdout, "Switching to preparation phase\n");
                currentPhase = PHASE_PREPARATION;
            }
            break;
    }
}

GAME_PHASE get_current_phase(void) {
    return currentPhase;
}

void switch_phase(GAME_PHASE p_phase) {
    currentPhase = p_phase;
}

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

    bool shouldClose = false;

    while (!WindowShouldClose() && !shouldClose) {
        handle_phase_transition();
        
        // Render based on current phase
            switch(currentPhase) {
        case PHASE_PREPARATION:
            BeginDrawing();
            ClearBackground(BLUE);
            DrawText("Preparation Phase", 10, 10, 20, BLACK);
            EndDrawing();
            WaitTime(1);
            break;
        case PHASE_BATTLE:
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Battle Phase", 10, 10, 20, BLACK);
            render_game(entityComponentManagerPtr);
            EndDrawing();
            WaitTime(1);
            break;
        case PHASE_RESULT:
            BeginDrawing();
            ClearBackground(PINK);
            DrawText("Result Phase", 10, 10, 20, BLACK);
            EndDrawing();
            WaitTime(1);
            break;
        case PHASE_POST_BATTLE:
            BeginDrawing();
            ClearBackground(YELLOW);
            DrawText("Post-Battle Phase", 10, 10, 20, BLACK);
            EndDrawing();
            WaitTime(1);
            shouldClose = true;
            break;
    }
        
    }

    destroy_component_manager(&entityComponentManagerPtr);
    return 0;
}