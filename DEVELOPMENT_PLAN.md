# Development Plan

## Basic Features

1. **Implement a basic game loop**:
    - Create a main file (`main.c`) that contains the game loop.

2. **Implement basic rendering**:
    - Use Raylib to draw the battlefield grid and units.
    - Display unit icons and health bars above each unit to indicate its current health.
    - Render artillery units below the battlefield based on the player's artillery value.

3. **Create a simple battlefield and place units on it**:
    - Implement a grid for the battlefield.
    - Allow the player to place their units on the first two rows of their side of the grid during the Preparation Phase.
    - Automatically place artillery units below the battlefield based on the player's artillery value (e.g., a value of 100 gives 1 cannon, and a value of 200 gives 2 cannons).

4. **Implement mouse input handling**:
    - Preparation Phase: Use the mouse to drag units to positions on the placement grid. Units can be repositioned after being placed.
    - Battle Phase: Select a unit with the mouse to display movement options. Choose a direction to move or select another unit. Allow the player to click "Skip Turn" at any time.
    - Result Phase: Use the mouse to navigate menu options.
    - Post-Battle Phase: Use the mouse to navigate menu options.

5. **Handle the phases of the game**:
    - Implement the phases of the game (Preparation Phase, Battle Phase, Result Phase, Post-Battle Phase).

6. **Implement basic battle logic**:
    - Create functions to handle attacks, counter-attacks, and movement.
    - Calculate damage based on the attacker's attack value minus the defender's defense value.
    - Handle the turn order between the player and the enemy.
    - Implement victory conditions: if a unit reaches the other side of the battlefield, that side wins; if all infantry and cavalry units on one side are defeated, the other side wins.

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

# Workflow

To manage the development process, we will use GitHub Issues and GitHub Projects. The workflow is as follows:

1. **GitHub Issues**:
    - Create issues for each feature or task that needs to be implemented.
    - Each issue should contain an overview of the feature or task, including any relevant details and acceptance criteria.

2. **GitHub Projects**:
    - Use GitHub Projects to organize and manage issues.
    - The project board will have the following phases:
        - **Backlog**: All issues that are not yet started.
        - **In Progress**: All issues that have code being worked on.
        - **In Review**: All issues that have a pull request submitted.
        - **Done**: All closed issues and merged pull requests.

3. **Workflow Steps**:
    - **Backlog**: Add new issues to the Backlog phase.
    - **In Progress**: Move issues to In Progress when work begins. Commit code changes to a new branch and reference the issue number in commit messages.
    - **In Review**: When a feature is complete, submit a pull request and move the issue to In Review. The pull request should be reviewed by another team member.
    - **Done**: Once the pull request is approved and merged, move the issue to Done and close it.
