#include "systems/entity_component_system.h"
#include "systems/sprite_loader_system.h"
#include "systems/memory_system.h"
#include "component_handler.h"
#include <stdlib.h>  // Add this for free()

EntityComponentManager* create_component_manager(void) {
    EntityComponentManager* manager = malloc(sizeof(EntityComponentManager));
    if (!manager) {
        return NULL;
    }

    manager->memoryManager = create_memory_manager(COMPONENT_TYPE_COUNT);
    if (!manager->memoryManager) {
        free(manager);
        return NULL;
    }

    manager->entityCount = 0;
    return manager;
}

COMPONENT_ID retrieve_entity_component(EntityComponentManager* p_componentManagerPtr,
                                     size_t p_entityId,
                                     COMPONENT_TYPE p_type) {
    if (p_entityId >= MAX_ENTITIES) {
        return -1;
    }
    return p_componentManagerPtr->componentMaps[p_entityId].componentIds[p_type];
}

void destroy_component_manager(EntityComponentManager** p_componentManagerPtr) {
    if (p_componentManagerPtr == NULL || *p_componentManagerPtr == NULL) {
        return;
    }

    // Loop through entities and get their sprite components
    for (size_t i = 0; i < (*p_componentManagerPtr)->entityCount; i++) {
        COMPONENT_ID spriteId = (*p_componentManagerPtr)->componentMaps[i].componentIds[COMPONENT_TYPE_SPRITE];
        if (spriteId != -1) {
            // Get sprite component directly from memory pool
            SpriteComponent* spriteComp = (SpriteComponent*)((char*)(*p_componentManagerPtr)->memoryManager->pools[COMPONENT_TYPE_SPRITE] +
                                         (spriteId * sizeof(SpriteComponent)));
            unload_sprite(spriteComp, 0);
        }
    }

    // Now it's safe to destroy memory manager and component manager
    destroy_memory_manager((*p_componentManagerPtr)->memoryManager);
    free(*p_componentManagerPtr);
    *p_componentManagerPtr = NULL;
}

COMPONENT_ID add_sprite_component(EntityComponentManager* p_componentManagerPtr,
                                SpriteComponent p_spriteComponent) {
    return add_component(p_componentManagerPtr,
                        COMPONENT_TYPE_SPRITE,
                        &p_spriteComponent,
                        sizeof(SpriteComponent));
}

COMPONENT_ID add_position_component(EntityComponentManager* p_componentManagerPtr,
                                  PositionComponent p_positionComponent) {
    return add_component(p_componentManagerPtr,
                        COMPONENT_TYPE_POSITION,
                        &p_positionComponent,
                        sizeof(PositionComponent));
}

COMPONENT_ID add_clickable_component(EntityComponentManager* p_componentManagerPtr,
                                   ClickableComponent p_clickableComponent) {
    return add_component(p_componentManagerPtr,
                        COMPONENT_TYPE_CLICKABLE,
                        &p_clickableComponent,
                        sizeof(ClickableComponent));
}

ENTITY_ID create_entity(EntityComponentManager* p_componentManagerPtr) {
    if (p_componentManagerPtr->entityCount >= MAX_ENTITIES) {
        return -1;
    }

    size_t entityId = p_componentManagerPtr->entityCount;
    p_componentManagerPtr->entities[entityId].id = entityId;
    p_componentManagerPtr->entityCount++;

    // Initialize component map for new entity
    for (size_t i = 0; i < COMPONENT_TYPE_COUNT; i++) {
        p_componentManagerPtr->componentMaps[entityId].componentIds[i] = -1;
    }

    return entityId;
}

bool is_entity_clicked(PositionComponent* p_positionComponent, int p_mouseX, int p_mouseY) {
    // Assuming the entity is represented by a rectangle with a fixed width and height
    int entityWidth = 50;  // Example width
    int entityHeight = 50; // Example height

    // Check if the mouse click is within the entity's bounds
    if (p_mouseX >= p_positionComponent->positionX && p_mouseX <= p_positionComponent->positionX + entityWidth &&
        p_mouseY >= p_positionComponent->positionY && p_mouseY <= p_positionComponent->positionY + entityHeight) {
        return true;
    }

    return false;
}
