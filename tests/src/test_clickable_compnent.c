#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "systems/entity_component_system.h"
#include "systems/memory_system.h"
#include "component_handler.h"

void test_clickable_component(void) {
    // Initialize the component manager
    EntityComponentManager* manager = create_component_manager();
    CU_ASSERT_PTR_NOT_NULL_FATAL(manager);

    // Create an entity first
    ENTITY_ID entityId = create_entity(manager);
    CU_ASSERT_NOT_EQUAL(entityId, -1);

    // Create and add clickable component
    ClickableComponent clickable = {
        .componentId = -1,  // Will be set by add_component
        .isClickable = true
    };

    // Add component to manager and get its ID
    COMPONENT_ID clickableId = add_clickable_component(manager, clickable);
    CU_ASSERT_NOT_EQUAL(clickableId, -1);

    // IMPORTANT: Link component to entity
    manager->componentMaps[entityId].componentIds[COMPONENT_TYPE_CLICKABLE] = clickableId;

    // Verify component was added correctly by retrieving it through the entity
    COMPONENT_ID retrievedId = retrieve_entity_component(manager, entityId, COMPONENT_TYPE_CLICKABLE);
    CU_ASSERT_EQUAL(retrievedId, clickableId);

    // Get and verify component data
    ClickableComponent* clickableComp = (ClickableComponent*)get_component(manager, 
                                                                         COMPONENT_TYPE_CLICKABLE, 
                                                                         clickableId);  // Use clickableId instead of retrievedId
    CU_ASSERT_PTR_NOT_NULL_FATAL(clickableComp);
    CU_ASSERT_TRUE(clickableComp->isClickable);

    // Test with position component for click detection
    PositionComponent pos = {-1, 100, 100};  // Initialize with -1 componentId
    COMPONENT_ID posId = add_position_component(manager, pos);
    CU_ASSERT_NOT_EQUAL(posId, -1);
    manager->componentMaps[entityId].componentIds[COMPONENT_TYPE_POSITION] = posId;

    // Test click detection
    PositionComponent* posComp = (PositionComponent*)get_component(manager, 
                                                                 COMPONENT_TYPE_POSITION, 
                                                                 posId);
    CU_ASSERT_PTR_NOT_NULL(posComp);
    
    // Test clicks at various positions
    CU_ASSERT_TRUE(is_entity_clicked(posComp, 100, 100));   // Direct hit
    CU_ASSERT_TRUE(is_entity_clicked(posComp, 120, 120));   // Within bounds
    CU_ASSERT_FALSE(is_entity_clicked(posComp, 200, 200));  // Outside bounds
    
    // Cleanup
    destroy_component_manager(&manager);
}