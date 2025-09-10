#ifndef COMPONENT_HANDLER_H
#define COMPONENT_HANDLER_H

#include <stddef.h>
#include "components/component.h"
#include "entity_component_manager.h"

typedef struct {
    void* data;
    size_t size;
    COMPONENT_TYPE type;
} ComponentData;

// Function declarations
COMPONENT_ID add_component(EntityComponentManager* manager,
                         COMPONENT_TYPE type,
                         void* data,
                         size_t size);

void* get_component(EntityComponentManager* manager,
                   COMPONENT_TYPE type,
                   COMPONENT_ID id);

void remove_component(EntityComponentManager* manager,
                     COMPONENT_TYPE type,
                     COMPONENT_ID id);

#endif // COMPONENT_HANDLER_H