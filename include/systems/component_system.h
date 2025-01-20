#ifndef MEMORY_SYSTEM_H
#define MEMORY_SYSTEM_H

#include "memory_manager.h"
#include "entity_component_manager.h"

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

#endif // MEMORY_SYSTEM_H