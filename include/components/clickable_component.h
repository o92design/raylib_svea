#ifndef CLICKABLE_COMPONENT_H
#define CLICKABLE_COMPONENT_H

#include "components/component.h"

typedef struct {
    COMPONENT_ID componentId;
    bool isClickable;
} ClickableComponent;

#endif // CLICKABLE_COMPONENT_H
