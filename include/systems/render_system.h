#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include <stddef.h>

#include "entity_component_manager.h"

void render_system(SpriteComponent* p_spriteComponentsPtr, PositionComponent* p_positionComponentsPtr);

#endif // RENDER_SYSTEM_H