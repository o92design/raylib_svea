#include "component_handler.h"
#include "entity_component_manager.h"
#include "systems/memory_system.h"
#include <stdio.h>
#include <string.h>

COMPONENT_ID add_component(EntityComponentManager* p_manager, 
                         COMPONENT_TYPE p_type,
                         void* p_data, 
                         size_t p_size) {
    if (!p_manager || !p_data) {
        return -1;
    }

    // Set element size for this component type if not already set
    if (p_manager->memoryManager->element_sizes[p_type] == 0) {
        p_manager->memoryManager->element_sizes[p_type] = p_size;
    }

    // Allocate memory for component
    void* component = allocate_component(p_manager->memoryManager, p_type);
    if (!component) {
        return -1;
    }

    // Copy component data
    memcpy(component, p_data, p_size);

    // Return component ID (for now just using the index)
    return p_manager->memoryManager->pool_sizes[p_type] - 1;
}

void* get_component(EntityComponentManager* p_manager,
                   COMPONENT_TYPE p_type,
                   COMPONENT_ID p_id) {
    if (!p_manager || p_type >= p_manager->memoryManager->type_count) {
        return NULL;
    }

    void* pool = p_manager->memoryManager->pools[p_type];
    if (!pool) {
        return NULL;
    }

    // Calculate component pointer using ID and element size
    return (char*)pool + (p_id * p_manager->memoryManager->element_sizes[p_type]);
}

void remove_component(EntityComponentManager* p_manager,
                     COMPONENT_TYPE p_type,
                     COMPONENT_ID p_id) {
    if (!p_manager || p_type >= p_manager->memoryManager->type_count) {
        return;
    }

    void* component = get_component(p_manager, p_type, p_id);
    if (!component) {
        return;
    }

    free_component(p_manager->memoryManager, p_type, component);
}

COMPONENT_ID add_clickable_component(EntityComponentManager* p_manager, 
                                   ClickableComponent p_clickableComponent) {
    return add_component(p_manager, 
                        COMPONENT_TYPE_CLICKABLE, 
                        &p_clickableComponent, 
                        sizeof(ClickableComponent));
}

ClickableComponent* get_clickable_component(EntityComponentManager* p_manager,
                                           COMPONENT_ID p_id) {
    return (ClickableComponent*)get_component(p_manager, 
                                             COMPONENT_TYPE_CLICKABLE, 
                                             p_id);
}

void remove_clickable_component(EntityComponentManager* p_manager,
                               COMPONENT_ID p_id) {
    remove_component(p_manager, 
                    COMPONENT_TYPE_CLICKABLE, 
                    p_id);
}
