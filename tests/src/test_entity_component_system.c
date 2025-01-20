#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "game_initialize.h"
#include "systems/entity_component_system.h"
#include "systems/memory_system.h"
#include "component_handler.h"
#include "systems/sprite_loader_system.h"

void test_create_component_manager(void) {
    EntityComponentManager* manager = create_component_manager();
    CU_ASSERT_PTR_NOT_NULL_FATAL(manager);
    
    // Test memory manager creation
    CU_ASSERT_PTR_NOT_NULL(manager->memoryManager);
    CU_ASSERT_EQUAL(manager->memoryManager->type_count, 2); // SPRITE and POSITION
    CU_ASSERT_PTR_NOT_NULL(manager->componentMaps);
    CU_ASSERT_EQUAL(manager->entityCount, 0);

    destroy_component_manager(&manager);
    CU_ASSERT_PTR_NULL(manager);
}

void test_add_components(void) {
    // Initialize game for sprite loading
    CU_ASSERT(initialize_game() == 0);
    
    EntityComponentManager* manager = create_component_manager();
    CU_ASSERT_PTR_NOT_NULL_FATAL(manager);

    // Add sprite component
    SpriteComponent sprite = load_sprite("res/img/viking.png");
    COMPONENT_ID spriteId = add_sprite_component(manager, sprite);
    CU_ASSERT_NOT_EQUAL(spriteId, -1);

    // Add position component
    PositionComponent pos = {-1, 100, 200};
    COMPONENT_ID posId = add_position_component(manager, pos);
    CU_ASSERT_NOT_EQUAL(posId, -1);

    // Verify components were added correctly
    void* spritePtr = get_component(manager, COMPONENT_TYPE_SPRITE, spriteId);
    CU_ASSERT_PTR_NOT_NULL(spritePtr);
    
    void* posPtr = get_component(manager, COMPONENT_TYPE_POSITION, posId);
    CU_ASSERT_PTR_NOT_NULL(posPtr);

    cleanup_game();
    
    destroy_component_manager(&manager);
}

void test_component_memory_management(void) {
    EntityComponentManager* manager = create_component_manager();
    CU_ASSERT_PTR_NOT_NULL_FATAL(manager);

    // Add multiple position components
    for (int i = 0; i < 20; i++) {
        PositionComponent pos = {-1, i * 10, i * 10};
        COMPONENT_ID id = add_position_component(manager, pos);
        CU_ASSERT_NOT_EQUAL(id, -1);
        
        // Verify component data
        void* comp = get_component(manager, COMPONENT_TYPE_POSITION, id);
        CU_ASSERT_PTR_NOT_NULL(comp);
        PositionComponent* posComp = (PositionComponent*)comp;
        CU_ASSERT_EQUAL(posComp->positionX, i * 10);
    }

    destroy_component_manager(&manager);
    CU_ASSERT_PTR_NULL(manager);
}

void test_entity_creation(void) {
    EntityComponentManager* manager = create_component_manager();
    CU_ASSERT_PTR_NOT_NULL_FATAL(manager);

    // Test creating multiple entities
    for (int i = 0; i < 5; i++) {
        ENTITY_ID entityId = create_entity(manager);
        CU_ASSERT_NOT_EQUAL(entityId, -1);
        CU_ASSERT_EQUAL(entityId, i);
        CU_ASSERT_EQUAL(manager->entities[entityId].id, entityId);
    }

    destroy_component_manager(&manager);
}

void test_component_retrieval(void) {
    EntityComponentManager* manager = create_component_manager();
    CU_ASSERT_PTR_NOT_NULL_FATAL(manager);

    // Create entity and add components
    ENTITY_ID entityId = create_entity(manager);
    PositionComponent pos = {-1, 100, 200};
    COMPONENT_ID posId = add_position_component(manager, pos);
    manager->componentMaps[entityId].componentIds[COMPONENT_TYPE_POSITION] = posId;

    // Test component retrieval
    COMPONENT_ID retrievedId = retrieve_entity_component(manager, entityId, COMPONENT_TYPE_POSITION);
    CU_ASSERT_EQUAL(retrievedId, posId);

    void* component = get_component(manager, COMPONENT_TYPE_POSITION, retrievedId);
    CU_ASSERT_PTR_NOT_NULL(component);
    
    PositionComponent* posComp = (PositionComponent*)component;
    CU_ASSERT_EQUAL(posComp->positionX, 100);
    CU_ASSERT_EQUAL(posComp->positionY, 200);

    destroy_component_manager(&manager);
}

void test_memory_pool_growth(void) {
    EntityComponentManager* manager = create_component_manager();
    CU_ASSERT_PTR_NOT_NULL_FATAL(manager);

    // Add more components than initial pool size to test growth
    for (int i = 0; i < INITIAL_POOL_SIZE + 5; i++) {
        PositionComponent pos = {-1, i, i};
        COMPONENT_ID id = add_position_component(manager, pos);
        CU_ASSERT_NOT_EQUAL(id, -1);
    }

    destroy_component_manager(&manager);
}