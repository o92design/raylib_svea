#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include <stddef.h>

#include "components/sprite_component.h"

void render_system(SpriteComponent* spriteComponents, size_t count);

#endif // RENDER_SYSTEM_H