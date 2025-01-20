#include "systems/entity_component_system.h"
#include "systems/sprite_loader_system.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EntityComponentManager* create_component_manager(void) {
    EntityComponentManager* p_componentManagerPtr = malloc(sizeof(EntityComponentManager));
    if (p_componentManagerPtr == NULL) {
        return NULL;
    }
    p_componentManagerPtr->entityCount = 0;
    memset(&p_componentManagerPtr->entities, 0, sizeof(p_componentManagerPtr->entities));
    memset(&p_componentManagerPtr->components, 0, sizeof(p_componentManagerPtr->components));
    memset(&p_componentManagerPtr->spriteMap, -1, sizeof(p_componentManagerPtr->spriteMap));
    memset(&p_componentManagerPtr->positionMap, -1, sizeof(p_componentManagerPtr->positionMap));
    printf("Allocated a new entityComponentManager\n");
    return p_componentManagerPtr;
}

void destroy_component_manager(EntityComponentManager** p_componentManagerPtr) {
    if (p_componentManagerPtr == NULL || *p_componentManagerPtr == NULL) {
        return;
    }

    // Free sprite components
    for (size_t i = 0; i < 3; i++) {
        if ((*p_componentManagerPtr)->components.spriteComponents[i] != NULL) {
            if ((*p_componentManagerPtr)->components.spriteComponents[i]->sprite.id != 0) {
                unload_sprite((*p_componentManagerPtr)->components.spriteComponents[i], 0);
            }

            free((*p_componentManagerPtr)->components.spriteComponents[i]);
            (*p_componentManagerPtr)->components.spriteComponents[i] = NULL;
        }
    }

    // Free position components
    for (size_t i = 0; i < (*p_componentManagerPtr)->entityCount; i++) {
        if ((*p_componentManagerPtr)->components.positionComponents[i] != NULL) {
            free((*p_componentManagerPtr)->components.positionComponents[i]);
            (*p_componentManagerPtr)->components.positionComponents[i] = NULL;
        }
    }

    free(*p_componentManagerPtr);
    *p_componentManagerPtr = NULL;
    printf("Destroyed an entityComponentManager\n");
}

size_t create_entity(EntityComponentManager* p_componentManagerPtr) {
    if(p_componentManagerPtr->entityCount >= MAX_ENTITIES) {
        return -1;
    }
    
    size_t entityId = p_componentManagerPtr->entityCount;
    p_componentManagerPtr->entities[entityId].id = entityId;
    p_componentManagerPtr->entityCount++;
    return entityId;
}

COMPONENT_ID add_sprite_component(EntityComponentManager* p_componentManagerPtr, SpriteComponent p_spriteComponent) {
    printf("allocates spriteComponent to %p\n", (void*)p_componentManagerPtr);
    for (size_t i = 0; i < 3; i++) {
        if (p_componentManagerPtr->components.spriteComponents[i] == NULL) {
            // Allocate new component
            p_componentManagerPtr->components.spriteComponents[i] = malloc(sizeof(SpriteComponent));
            if (p_componentManagerPtr->components.spriteComponents[i] == NULL) {
                return -1;
            }
            // Copy component data
            *p_componentManagerPtr->components.spriteComponents[i] = p_spriteComponent;
            return i;
        }
    }
    return -1;
}

COMPONENT_ID add_position_component(EntityComponentManager* p_componentManagerPtr, PositionComponent p_positionComponent) {
    printf("allocates positionComponents to %p\n", (void*)p_componentManagerPtr);
    for (size_t i = 0; i < 3; i++) {
        if (p_componentManagerPtr->components.positionComponents[i] == NULL) {
            p_componentManagerPtr->components.positionComponents[i] = malloc(sizeof(PositionComponent));
            if (p_componentManagerPtr->components.positionComponents[i] == NULL) {
                return -1; // Memory allocation failed
            }
            *(p_componentManagerPtr->components.positionComponents[i]) = p_positionComponent;
            p_componentManagerPtr->components.positionComponents[i]->componentId = i;
            printf("allocated positionComponents with id: %ld\n", i);
            return i;
        }
    }
    return -1; // No available slot for the component
}

COMPONENT_ID retrieve_entity_component(EntityComponentManager* p_componentManagerPtr, size_t p_entityId, COMPONENT_TYPE p_type) {
    switch(p_type) {
        case COMPONENT_TYPE_SPRITE:
            return p_componentManagerPtr->spriteMap[p_entityId].componentId;
        case COMPONENT_TYPE_POSITION:
            return p_componentManagerPtr->positionMap[p_entityId].componentId;
        default:
            return -1; // Invalid component type
    }
}