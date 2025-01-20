#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "components/component.h"

#include "raylib.h"

typedef struct {
    COMPONENT_ID componentId;
    Texture2D sprite;
} SpriteComponent;

#endif // SPRITE_COMPONENT_H