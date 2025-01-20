#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include "components/component.h"

typedef struct {
    COMPONENT_ID componentId;
    int positionX;
    int positionY;
} PositionComponent;

#endif // POSITION_COMPONENT_H