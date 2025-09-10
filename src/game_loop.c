#include "game_loop.h"
#include "game_render.h"
#include <stdio.h>
#include <stdbool.h>

#include "game_initialize.h"
#include "systems/sprite_loader_system.h"
#include "systems/entity_component_system.h"

#include "log_system.h"

// Add to struct or global state
static GAME_PHASE currentPhase = PHASE_PREPARATION;

bool is_preparation_complete(void) {
    log_info("Preparation complete\n");
    return true;
}

bool is_battle_complete(void) {
    log_info("Battle complete\n");
    return true;
}

bool is_result_complete(void) {
    log_info("Result complete\n");
    return true;
}

bool is_post_battle_complete(void) {
    log_info("Post battle complete\n");
    return true;
}

void handle_phase_transition(void) {
    switch(currentPhase) {
        case PHASE_PREPARATION:
            if (is_preparation_complete()) {
                log_info("Switching to battle phase\n");
                currentPhase = PHASE_BATTLE;
            }
            break;
        case PHASE_BATTLE:
            if (is_battle_complete()) {
                log_info("Switching to result phase\n");
                currentPhase = PHASE_RESULT;
            }
            break;
        case PHASE_RESULT:
            if (is_result_complete()) {
                log_info("Switching to post battle phase\n");
                currentPhase = PHASE_POST_BATTLE;
            }
            break;
        case PHASE_POST_BATTLE:
            if (is_post_battle_complete()) {
                log_info("Switching to preparation phase\n");
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

    // Create Clickable Component
    ClickableComponent clickableComponent = {-1, true};
    COMPONENT_ID clickableId = add_clickable_component(entityComponentManagerPtr, clickableComponent);
    entityComponentManagerPtr->componentMaps[entityId].componentIds[COMPONENT_TYPE_CLICKABLE] = clickableId;

    ClickableComponent clickableComponentTwo = {-1, false};
    COMPONENT_ID clickableIdTwo = add_clickable_component(entityComponentManagerPtr, clickableComponentTwo);
    entityComponentManagerPtr->componentMaps[entityIdTwo].componentIds[COMPONENT_TYPE_CLICKABLE] = clickableIdTwo;

    bool shouldClose = false;

    bool shouldSwitch = true;
    while (!WindowShouldClose() && !shouldClose) {
        if(shouldSwitch) handle_phase_transition();

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
                shouldSwitch = false;
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("Battle Phase", 10, 10, 20, BLACK);
                render_game(entityComponentManagerPtr);
                EndDrawing();
                        // Register mouse clicks
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    int mouseX = GetMouseX();
                    int mouseY = GetMouseY();

                    // Check if clicking on an entity
                    for (size_t entityIndex = 0; entityIndex < entityComponentManagerPtr->entityCount; entityIndex++) {
                        size_t entityId = entityComponentManagerPtr->entities[entityIndex].id;

                        // Get component IDs
                        COMPONENT_ID positionComponentId = retrieve_entity_component(entityComponentManagerPtr, entityId, COMPONENT_TYPE_POSITION);
                        COMPONENT_ID clickableComponentId = retrieve_entity_component(entityComponentManagerPtr, entityId, COMPONENT_TYPE_CLICKABLE);

                        // Get actual components using component handler
                        PositionComponent* positionComponentPtr = get_component(entityComponentManagerPtr, COMPONENT_TYPE_POSITION, positionComponentId);
                        ClickableComponent* clickableComponentPtr = get_component(entityComponentManagerPtr, COMPONENT_TYPE_CLICKABLE, clickableComponentId);

                        if (positionComponentPtr && clickableComponentPtr && clickableComponentPtr->isClickable) {
                            if (is_entity_clicked(positionComponentPtr, mouseX, mouseY)) {
                                log_info("Entity %zu clicked\n", entityId);
                            }
                        }
                    }

                    // Check if clicking on a specific area of the screen
                    int areaX = 100;  // Example area position
                    int areaY = 100;  // Example area position
                    int areaWidth = 200;  // Example area size
                    int areaHeight = 200;  // Example area size

                    log_info("MouseX: %d, MouseY: %d\n", mouseX, mouseY);

                    if (mouseX >= areaX && mouseX <= areaX + areaWidth &&
                        mouseY >= areaY && mouseY <= areaY + areaHeight) {
                        log_info("Specific area clicked\n");
                        shouldSwitch = true;
                    }
                }

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
