# Architecture

## Overview

This project uses an Entity-Component-System (ECS) design to create a modular and scalable game. ECS separates data (components) from logic (systems) and makes it easy to add new features without changing existing code.

We use [Raylib](https://github.com/raysan5/raylib) as the underlying framework for handling graphics, sound, and user input. Raylib provides a simple and easy-to-use API that helps us focus on game development.

## Modules and Responsibilities

1. **ecs.h / ecs.c**:
    - Manages the creation and management of entities and components.
    - Contains functions to add and remove components from entities.

2. **components/**:
    - **position_component.h / position_component.c**: Contains data for an entity's position.
    - **health_component.h / health_component.c**: Contains data for an entity's health.
    - **attack_component.h / attack_component.c**: Contains data for an entity's attack value.
    - **render_component.h / render_component.c**: Contains data for an entity's sprite and animations.

3. **systems/**:
    - **render_system.h / render_system.c**: Handles rendering of entities based on their components.
    - **movement_system.h / movement_system.c**: Handles movement of entities based on their components.
    - **combat_system.h / combat_system.c**: Handles combat between entities based on their components.
    - **preparation_system.h / preparation_system.c**: Handles logic for the preparation phase.
    - **battle_system.h / battle_system.c**: Handles logic for the battle phase.
    - **result_system.h / result_system.c**: Handles logic for the result phase.
    - **post_battle_system.h / post_battle_system.c**: Handles logic for the post-battle phase.

4. **game.h / game.c**:
    - Manages the overall game logic and state.
    - Initializes and shuts down the game.
    - Updates the game state based on user input and game rules.
    - Handles transitions between the different phases.

5. **main.c**:
    - Contains the main game loop and initializes the various components.

## Phases of the Game

For a detailed description of the phases of the game, see the "Phases of the Game" section in [README.md](README.md#phases-of-the-game).

## Example Components and Systems

### Position Component

```c
// filepath: include/components/position_component.h
#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

typedef struct {
    float x;
    float y;
} PositionComponent;

#endif // POSITION_COMPONENT_H
```

### Health Component

```c
// filepath: include/components/health_component.h
#ifndef HEALTH_COMPONENT_H
#define HEALTH_COMPONENT_H

typedef struct {
    int health;
} HealthComponent;

#endif // HEALTH_COMPONENT_H
```

### Render System
```c
// filepath: src/systems/render_system.c
#include "raylib.h"
#include "components/position_component.h"
#include "components/health_component.h"

void RenderSystem(Entity *entities, int entityCount)
{
    for (int i = 0; i < entityCount; i++)
    {
        PositionComponent *position = GetComponent(entities[i], POSITION_COMPONENT);
        HealthComponent *health = GetComponent(entities[i], HEALTH_COMPONENT);

        if (position && health)
        {
            DrawCircle(position->x, position->y, 20, RED);
            DrawText(TextFormat("HP: %d", health->health), position->x - 20, position->y - 30, 10, BLACK);
        }
    }
}
```