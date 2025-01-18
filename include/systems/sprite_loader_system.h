#ifndef SPRITE_LOADER_SYSTEM_H
#define SPRITE_LOADER_SYSTEM_H

#include "components/sprite_component.h"
#include <stddef.h>

SpriteComponent load_sprite(const char* p_pathPtr);
int unload_sprite(SpriteComponent* p_spriteComponentPtr, const size_t p_index);
int unload_sprites(SpriteComponent* p_spriteComponentsPtr, const size_t p_count);

#endif // SPRITE_LOADER_SYSTEM_H