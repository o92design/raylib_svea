# Development Plan

## Basic Features

1. **Implement a basic game loop**:
    - Create a main file (`main.c`) that contains the game loop.
    - Handle the phases of the game (Preparation Phase, Battle Phase, Result Phase, Post-Battle Phase).

2. **Create a simple battlefield and place units on it**:
    - Implement a grid for the battlefield.
    - Allow the player to place their units on the battlefield.
    - Automatically place artillery based on the number of units.

3. **Implement basic battle logic**:
    - Create functions to handle attacks, counter-attacks, and movement.
    - Calculate damage based on the attacker's attack value minus the defender's defense value.
    - Handle the turn order between the player and the enemy.

## Extended Features

1. **Add more unit types and improve battle logic**:
    - Implement more unit types (e.g., archers, spearmen).
    - Add more actions per turn (e.g., defend, special abilities).

2. **Implement a grid for the battlefield with circles as graphical elements**:
    - Use Raylib to draw the battlefield and units.
    - Implement different types of terrain that affect unit movement and combat abilities.

3. **Add graphics and sound**:
    - Use icons to represent different unit types.
    - Display a health bar above each unit to indicate its current health.
    - Add sound effects for attacks, damage, and special abilities.
    - Add background music for battles.

## Testing and Debugging

1. **Regularly test the game to find and fix bugs**:
    - Use unit tests to ensure that the battle logic works correctly.
    - Manually test the game to find and fix bugs.

2. **Use unit tests to ensure that the battle logic works correctly**:
    - Create unit tests for the different functions in the game.
    - Use a testing library like Unity or CMocka to write and run the tests.