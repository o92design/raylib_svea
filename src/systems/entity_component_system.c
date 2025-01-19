#include "systems/entity_component_system.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EntityComponentManager* create_component_manager(void) {
    EntityComponentManager* p_componentManagerPtr = malloc(sizeof(EntityComponentManager));
    if (p_componentManagerPtr == NULL) {
        return NULL;
    }
    p_componentManagerPtr->entityCount = 0;
    memset(p_componentManagerPtr->entities, 0, sizeof(p_componentManagerPtr->entities));
    memset(&p_componentManagerPtr->components, 0, sizeof(p_componentManagerPtr->components));

    printf("Allocated a new entityComponentManger\n");
    return p_componentManagerPtr;
}

void destroy_component_manager(EntityComponentManager** p_componentManagerPtr) {
    for (size_t i = 0; i < 3; i++) {
        if ((*p_componentManagerPtr)->components.spriteComponents[i] != NULL) {
            free((*p_componentManagerPtr)->components.spriteComponents[i]);
            (*p_componentManagerPtr)->components.spriteComponents[i] = NULL;
        }
    }
    for (size_t i = 0; i < MAX_ENTITIES; i++) {
        if ((*p_componentManagerPtr)->components.positionComponents[i] != NULL) {
            free((*p_componentManagerPtr)->components.positionComponents[i]);
            (*p_componentManagerPtr)->components.positionComponents[i] = NULL;
        }
    }
    free(*p_componentManagerPtr);
    *p_componentManagerPtr = NULL;
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

COMPONENT_ID add_sprite_component(EntityComponentManager* p_componentManagerPtr, SpriteComponent spriteComponent) {
    printf("allocates spritesComponent to %p\n", (void*)p_componentManagerPtr);
    for (size_t i = 0; i < 3; i++) {
        if (p_componentManagerPtr->components.spriteComponents[i] == NULL) {
            p_componentManagerPtr->components.spriteComponents[i] = malloc(sizeof(SpriteComponent));
            if (p_componentManagerPtr->components.spriteComponents[i] == NULL) {
                return -1; // Memory allocation failed
            }
            *(p_componentManagerPtr->components.spriteComponents[i]) = spriteComponent;
            p_componentManagerPtr->components.spriteComponents[i]->componentId = i;
            printf("allocated spriteComponent with id: %ld\n", i);
            return i;
        }
    }
    return -1; // No available slot for the component
}