#ifndef ENTITY_COMPONENT_SYSTEM_H
#define ENTITY_COMPONENT_SYSTEM_H

#include "entity_component_manager.h"

EntityComponentManager* create_component_manager(void);
void destroy_component_manager(EntityComponentManager** p_componentManagerPtr);
size_t create_entity(EntityComponentManager* p_componentManagerPtr);
COMPONENT_ID add_sprite_component(EntityComponentManager* p_componentManagerPtr, SpriteComponent p_spriteComponent);
COMPONENT_ID add_position_component(EntityComponentManager* p_componentManagerPtr, PositionComponent p_positionComponent);
COMPONENT_ID retrieve_entity_component(EntityComponentManager* p_componentManagerPtr, size_t p_entityId, COMPONENT_TYPE p_type);

#endif // ENTITY_COMPONENT_SYSTEM_H