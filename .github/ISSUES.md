# Issues for o92design/raylib_svea

## [Implement Entity and Component Management](https://github.com/o92design/raylib_svea/issues/7)
**Description**
Implement the basic entity and component management system to manage game entities and their components.

**Acceptance Criteria**
- [ ] Create an entity system to manage game entities.
- [ ] Ensure that entities can be created, updated, and destroyed.
- [ ] Implement a basic component system to manage components.
- [ ] Ensure that components can be added to and removed from entities.

**Additional Context**
This issue is to set up the basic entity and component management system for the game.

## [Implement Mouse Input Handling for Preparation Phase](https://github.com/o92design/raylib_svea/issues/6)
**Description**
Implement mouse input handling for the Preparation Phase.

**Acceptance Criteria**
- [ ] Use the mouse to drag units to positions on the placement grid.
- [ ] Allow units to be repositioned after being placed.

**Additional Context**
This issue is to implement mouse input handling for the Preparation Phase.

## [Implement Basic Mouse Click Handling](https://github.com/o92design/raylib_svea/issues/5)
**Description**
Implement basic mouse click handling to register clicks and determine what the player is clicking on.

**Acceptance Criteria**
- [ ] Implement functionality to register mouse clicks.
- [ ] Determine if the player is clicking on an entity or a specific area of the screen.

**Additional Context**
This issue is to set up basic mouse click handling to register clicks and determine what the player is clicking on.

## [Implement Phase Transitions](https://github.com/o92design/raylib_svea/issues/4)
**Description**
Implement the ability to transition between the different phases of the game (Preparation Phase, Battle Phase, Result Phase, Post-Battle Phase).

**Acceptance Criteria**
- [ ] Implement the ability to transition from the Preparation Phase to the Battle Phase.
- [ ] Implement the ability to transition from the Battle Phase to the Result Phase.
- [ ] Implement the ability to transition from the Result Phase to the Post-Battle Phase.
- [ ] Implement the ability to transition from the Post-Battle Phase to the Preparation Phase.

**Additional Context**
This issue is to set up the basic phase transitions for the game.

## [Implement Basic Rendering](https://github.com/o92design/raylib_svea/issues/3)
**Description**
Implement basic rendering using Raylib to display an image on the screen.

**Acceptance Criteria**
- [ ] Use Raylib to initialize a window.
- [ ] Load an image and display it on the screen.

**Additional Context**
This issue is to set up the basic rendering for the game using Raylib by displaying an image on the screen.

## [Implement Basic Game Loop](https://github.com/o92design/raylib_svea/issues/2)
**Description**
Implement a basic game loop that runs continuously until the game is exited.

**Acceptance Criteria**
- [ ] Create a main file (`main.c`) that calls initialize and calls the game loop.
- [ ] Create a game loop files (`game_initialize.h` and `game_initialize.c`) that contains the game loop
- [ ] Create a game loop files (`game_loop.h` and `game_loop.c`) that contains the game loop
- [ ] Ensure the game loop runs continuously until the game is exited.

**Additional Context**
This issue is to set up the basic game loop that will manage the different phases of the game.

## [Project structure](https://github.com/o92design/raylib_svea/issues/1)
**Description**
Create the initial project structure for the Svea Rike 2 Clone project.

**Acceptance Criteria**
- [ ] Create the following directories:
  - `.github/ISSUE_TEMPLATE/`
  - `.vscode/`
  - `include/components/`
  - `src/systems/`
  - `lib/`
- [ ] Create the following files:
  - `.gitignore`
  - `ARCHITECTURE.md`
  - `DEVELOPMENT_PLAN.md`
  - `README.md`
  - `.github/ISSUE_TEMPLATE/bug_report.md`
  - `.github/ISSUE_TEMPLATE/config.yml`
  - `.github/ISSUE_TEMPLATE/feature.md`
  - `.vscode/c_cpp_properties.json`
  - `.vscode/launch.json`
  - `.vscode/settings.json`
  - `Makefile`

**Additional Context**
This issue is to set up the initial project structure and create the necessary directories and files to get started with the development of the Svea Rike 2 Clone project. Raylib will be placed in the `lib` directory and linked dynamically. The `Makefile` will be used to build the project.