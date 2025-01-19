#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "systems/entity_component_system.h"
#include "systems/sprite_loader_system.h"

void test_create_component_manager(void) {
    EntityComponentManager* entityComponentManagerPtr = create_component_manager();
    CU_ASSERT_PTR_NOT_NULL_FATAL(entityComponentManagerPtr);
    CU_ASSERT_EQUAL(entityComponentManagerPtr->entityCount, 0);
    destroy_component_manager(&entityComponentManagerPtr);
    CU_ASSERT_PTR_NULL_FATAL(entityComponentManagerPtr);
}

void test_create_entity(void) {
    EntityComponentManager* entityComponentManagerPtr = create_component_manager();
    
    for(size_t entityIndex = 0; entityIndex < MAX_ENTITIES; entityIndex++) {
        create_entity(entityComponentManagerPtr);
        CU_ASSERT_EQUAL(entityComponentManagerPtr->entityCount, entityIndex + 1);
        CU_ASSERT_EQUAL(entityComponentManagerPtr->entities[0].id, 0);
    }

    int nonCreatedEntity = create_entity(entityComponentManagerPtr);
    CU_ASSERT_EQUAL(nonCreatedEntity, -1);
    CU_ASSERT_EQUAL(entityComponentManagerPtr->entityCount, MAX_ENTITIES);
    CU_ASSERT_EQUAL(entityComponentManagerPtr->entities[MAX_ENTITIES - 1].id, MAX_ENTITIES - 1);
    CU_ASSERT_EQUAL(entityComponentManagerPtr->entities[0].id, 0);

    destroy_component_manager(&entityComponentManagerPtr);
}

//TODO(kioskars, 19/1-25): Test doesn't work when loading in the image, need investigation since other tests work -.-
void test_create_entity_with_sprite_component(void) {
    EntityComponentManager* entityComponentManagerPtr = create_component_manager();
    CU_ASSERT_PTR_NOT_NULL_FATAL(entityComponentManagerPtr);

    size_t entityId = create_entity(entityComponentManagerPtr);
    CU_ASSERT_NOT_EQUAL(entityId, -1);

    SpriteComponent spriteComponent = load_sprite("res/img/viking.png");
    CU_ASSERT_NOT_EQUAL(spriteComponent.sprite.id, 0);

    COMPONENT_ID componentId = add_sprite_component(entityComponentManagerPtr, spriteComponent);
    CU_ASSERT_NOT_EQUAL(componentId, -1);

    CU_ASSERT_EQUAL(entityComponentManagerPtr->components.spriteComponents[componentId]->componentId, componentId);
    CU_ASSERT_NOT_EQUAL(entityComponentManagerPtr->components.spriteComponents[componentId]->sprite.id, 0);
    CU_ASSERT_EQUAL(entityComponentManagerPtr->components.spriteComponents[componentId]->sprite.id, spriteComponent.sprite.id);

    destroy_component_manager(&entityComponentManagerPtr);
    CU_ASSERT_PTR_NULL_FATAL(entityComponentManagerPtr);
}