#ifndef ENTITY_COMPONENT_MANAGER_H
#define ENTITY_COMPONENT_MANAGER_H

#include "id_types.h"
#include "entity.h"
#include "components/sprite_component.h"
#include "components/position_component.h"
#include "components/clickable_component.h"
#include "memory_manager.h"

#define MAX_ENTITIES 100

typedef struct {
    COMPONENT_ID componentIds[3];  // Array to store different component types
} ComponentMap;

typedef struct {
    Entity entities[MAX_ENTITIES];
    size_t entityCount;
    MemoryManager* memoryManager;
    ComponentMap componentMaps[MAX_ENTITIES];
} EntityComponentManager;

#endif // ENTITY_COMPONENT_MANAGER_H