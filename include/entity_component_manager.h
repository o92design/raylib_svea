#ifndef ENTITY_COMPONENT_MANAGER_H
#define ENTITY_COMPONENT_MANAGER_H

#include "components/component.h"
#include "components/sprite_component.h"
#include "components/position_component.h"
#include "entity.h"

#define MAX_ENTITIES 100

typedef struct {
    SpriteComponent* spriteComponents[3];
    PositionComponent* positionComponents[MAX_ENTITIES];
}Components;

/* We map components towards entityId so that we can faster lookup what data we want to retrieve */
typedef struct {
    COMPONENT_ID componentId;
} ComponentMap;

typedef struct {
    Entity entities[MAX_ENTITIES];
    size_t entityCount;
    Components components;
    ComponentMap spriteMap[MAX_ENTITIES];
    ComponentMap positionMap[MAX_ENTITIES];
} EntityComponentManager;


/** EXAMPLE CODE FOR NOW
render(EntityComponentManagerPtr, entityId) {
    spriteId = EntityComponentManagerPtr->spriteMap[entityId].componentId;
    positionId = EntityComponentManagerPtr->positionMap[entityId].componentId;
    render_component(componentId, positionId);
}
/**/

#endif // ENTITY_COMPONENT_MANAGER_H