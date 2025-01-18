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
    - **grid_component.h / grid_component.c**: Contains data for the battlefield grid, including dimensions and unit positions.

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

## Mouse Input Handling

Mouse input is handled differently depending on the phase of the game. The `input_system` is responsible for capturing mouse events and updating the game state accordingly.

1. **Preparation Phase**:
    - **Mouse Input**: Use the mouse to drag units to positions on the placement grid. Units can be repositioned after being placed.
    - The `input_system` captures drag-and-drop events and updates the position components of the units.

2. **Battle Phase**:
    - **Mouse Input**: Select a unit with the mouse to display movement options. Choose a direction to move or select another unit. You can also click "Skip Turn" at any time.

3. **Result Phase**:
    - **Mouse Input**: Use the mouse to navigate menu options.
    - The `input_system` captures click events to navigate through the result menus.

4. **Post-Battle Phase**:
    - **Mouse Input**: Use the mouse to navigate menu options.
    - The `input_system` captures click events to navigate through the post-battle menus.

## Example Components and Systems

### Position Component

```c
// filepath: include/components/position_component.h
#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

typedef struct {
    int x;
    int y;
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
### Grid Component
```c
// filepath: include/components/grid_component.h
#ifndef GRID_COMPONENT_H
#define GRID_COMPONENT_H

typedef struct {
    int x;
    int y;
    int **unit_positions; // 2D array to store unit positions on the grid
} GridComponent;

#endif // GRID_COMPONENT_H
```

### Render System
```c
// filepath: src/systems/render_system.c
#include "raylib.h"
#include "components/position_component.h"
#include "components/health_component.h"
#include "components/grid_component.h"

void RenderSystem(Entity *entities, int entityCount, GridComponent *grid)
{
    for (int i = 0; i < entityCount; i++)
    {
        PositionComponent *position = GetComponent(entities[i], POSITION_COMPONENT);
        HealthComponent *health = GetComponent(entities[i], HEALTH_COMPONENT);

        if (position && health)
        {
            // Calculate screen position based on grid position
            float screenX = grid->x + position->x * GRID_CELL_WIDTH;
            float screenY = grid->y + position->y * GRID_CELL_HEIGHT;

            DrawCircle(screenX, screenY, 20, RED);
            DrawText(TextFormat("HP: %d", health->health), screenX - 20, screenY - 30, 10, BLACK);
        }
    }
}
```
## Code Structure

To maintain consistency and readability, follow these guidelines for code structure:

1. **Struct Names**:
    - Use `UpperCase` for typedef names.
    - Example `typedef struct { ... } EntityComponent`

2. **Variable Names**:
    - Use `lowerCase` for variables.
    - Example `EntityComponent entityComponent`

3. **Function Names**:
    - Use `lower_case` for function names.
    - Example: `void render_system(Entity* p_entitiesPtr, int p_entity_count);`

4. **Parameter Names**:
    - Use `p_parameterName` for parameters.
    - Use `* p_parameterNamePtr` for pointer parameters.
    - Use `const p_parameterNameRef` for constant reference parameters.
    - Example: `void move_entity(Entity *p_entityPtr, const PositionComponent *p_positionPtr);`

5. **File Naming**:
    - Use `snake_case` for file names.
    - Example: `position_component.h`, `render_system.c`

6. **Indentation and Spacing**:
    - Use 4 spaces for indentation.
    - Place a space between keywords and parentheses.
    - Example: `if (condition) { ... }`

7. **Comments**:
    - Use `//` for single-line comments.
    - Use `/* ... */` for multi-line comments.
    - Place comments above the code they describe.
    - Example:
      ```c
      // Initialize the game
      void init_game(void) {
          /*
          A comment that stretches over 
          several rows and used for detailed 
          information about the code
          */
         // Code here
      }
      ```
8. **TODOs**:
    - Use //TODO(author, DD-MM-YYYY): reason
    - Example:
    ```c
    // TODO(kioskars, 18-1-2025): refactor code for better use

# Automated Testing

To ensure the reliability and correctness of the game, we use automated testing. The following tools and practices are used:

1. **Unit Testing**:
    - We use [CUnit](http://cunit.sourceforge.net/) to write and run unit tests.
    - Unit tests are written for individual components and systems to verify their functionality.

2. **Continuous Integration (CI)**:
    - We use a CI service like [GitHub Actions](https://github.com/features/actions) to automatically run tests on every push and pull request.
    - The CI pipeline is configured to compile the code, run unit tests, and report the results.

3. **Code Coverage**:
    - We use tools like [gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) to measure code coverage.
    - Code coverage reports help us identify untested parts of the codebase and improve test coverage.

4. **Static Analysis**:
    - We use static analysis tools like [Cppcheck](http://cppcheck.sourceforge.net/) to detect potential issues in the code.
    - Static analysis is integrated into the CI pipeline to ensure code quality.

By following these practices, we aim to maintain a high level of code quality and ensure that the game behaves as expected.