# Issues for raylib_svea

## Open Issues

### [Refactor Memory Management System](https://github.com/o92design/raylib_svea/issues/13)
**Description:**  
Refactor the memory management system to be more generic and reusable across different parts of the game.

**Progress:** Open

**Acceptance Criteria:**
- [ ] Create abstract memory allocation interface
- [ ] Separate component-specific allocation from generic memory management
- [ ] Implement default allocation strategy
- [ ] Allow for custom allocation strategies
- [ ] Update EntityComponentManager to use the new memory system
- [ ] Add unit tests for different allocation strategies
- [ ] Ensure backward compatibility with existing component system

**Technical Notes:**
- Create MemoryAllocator interface
- Implement default malloc/free based allocator
- Update MemoryManager to use allocation strategy
- Keep current component pool functionality

---

### [Implement Mouse Input Handling for Preparation Phase](https://github.com/o92design/raylib_svea/issues/6)
**Description:**  
Implement mouse input handling for the Preparation Phase.

**Progress:** Open

**Acceptance Criteria:**
- [ ] Use the mouse to drag units to positions on the placement grid.
- [ ] Allow units to be repositioned after being placed.

---

### [Implement Basic Mouse Click Handling](https://github.com/o92design/raylib_svea/issues/5)
**Description:**  
Implement basic mouse click handling to register clicks and determine what the player is clicking on.

**Progress:** In Progress

**Acceptance Criteria:**
- [x] Implement functionality to register mouse clicks.
- [x] Determine if the player is clicking on an entity or a specific area of the screen.

---

## Closed Issues

### [Implement Phase Transitions](https://github.com/o92design/raylib_svea/issues/4)
**Description:**  
Implement the ability to transition between the different phases of the game (Preparation Phase, Battle Phase, Result Phase, Post-Battle Phase).

**Progress:** Closed (Completed)

**Acceptance Criteria:**
- [x] Implement the ability to transition from the Preparation Phase to the Battle Phase.
- [x] Implement the ability to transition from the Battle Phase to the Result Phase.
- [x] Implement the ability to transition from the Result Phase to the Post-Battle Phase.
- [x] Implement the ability to transition from the Post-Battle Phase to the Preparation Phase.

**Pull Requests:**
[#15 Implement Entity and Component Management](https://github.com/o92design/raylib_svea/issues/15)
***Description***
This pull request introduces a new feature for handling phase transitions in the game, along with corresponding updates to the documentation and tests. The most important changes include the addition of phase transition logic, updates to the game loop, and new tests to verify the functionality.

---

### [Implement Entity and Component Management](https://github.com/o92design/raylib_svea/issues/7)
**Description:**  
Implement the basic entity and component management system to manage game entities and their components.

**Progress:** Closed (Completed)

**Acceptance Criteria:**
- [x] Create an entity system to manage game entities.
- [x] Ensure that entities can be created, updated, and destroyed.
- [x] Implement a basic component system to manage components.
- [x] Ensure that components can be added to and removed from entities.

**Pull Request:**
[#14 Implement Entity and Component Management](https://github.com/o92design/raylib_svea/issues/14)
***Description***
This pull request includes significant changes to the memory management and entity-component systems to improve their functionality and flexibility. The most important changes include the introduction of a new memory management system, updates to the entity-component management, and modifications to the build process to support these changes.

---

### [Implement Basic Rendering](https://github.com/o92design/raylib_svea/issues/3)
**Description:**  
Implement basic rendering using Raylib to display an image on the screen.

**Progress:** Closed (Completed)

**Acceptance Criteria:**
- [x] Use Raylib to initialize a window.
- [x] Load an image and display it on the screen.

**Pull Request:**  
[#11 Implement Basic Rendering](https://github.com/o92design/raylib_svea/pull/11)  
***Description***  
This pull request includes several changes to the `Makefile`, the addition of new game-related source and header files, and updates to the test suite. The most important changes include updates to the `Makefile` to handle object files more efficiently, the addition of new game initialization and loop functions, and the restructuring and expansion of the test suite.

---

### [Implement Basic Game Loop](https://github.com/o92design/raylib_svea/issues/2)
**Description:**  
Implement a basic game loop that runs continuously until the game is exited.

**Progress:** Closed (Completed)

**Acceptance Criteria:**
- [x] Write unit tests to verify the game loop initialization and execution.
- [x] Create a main file (`main.c`) that contains the game loop.
- [x] Create game loop files (`game_initialize.h` and `game_initialize.c`) that contain the game loop.
- [x] Create game loop files (`game_loop.h` and `game_loop.c`) that contain the game loop.
- [x] Ensure the game loop runs continuously until the game is exited.

**Pull Request:**  
[#11 Implement Basic Game Loop](https://github.com/o92design/raylib_svea/pull/11)  
***Description:***  
This pull request includes several changes to the `Makefile`, the addition of new game-related source and header files, and updates to the test suite. The most important changes include updates to the `Makefile` to handle object files more efficiently, the addition of new game initialization and loop functions, and the restructuring and expansion of the test suite.

---

### [Set Up Test-Driven Development Environment](https://github.com/o92design/raylib_svea/issues/8)
**Description:**  
Set up the environment for test-driven development (TDD) by configuring the necessary tools and writing initial tests.

**Progress:** Closed (Completed)

**Acceptance Criteria:**
- [x] Install and configure a unit testing framework (CUnit).
- [x] Create a directory for tests (e.g., `tests/`).
- [x] Write basic initial unit tests for checking that it works.
- [x] Integrate unit tests into the build process using the `Makefile`.

**Pull request:**  
[#10 Setup Test-Driven Development Environment](https://github.com/o92design/raylib_svea/pull/10)  
***Description:***  
This pull request introduces test-driven development (TDD) by integrating the CUnit framework into the project and setting up the necessary infrastructure for unit testing.

---

### [Project structure](https://github.com/o92design/raylib_svea/issues/1)
**Description:**  
Create the initial project structure for the Svea Rike 2 Clone project.

**Progress:** Closed (Completed)

**Acceptance Criteria:**
- [x] Create the following directories:
  - `.github/ISSUE_TEMPLATE/`
  - `.vscode/`
  - `include/components/`
  - `src/systems/`
  - `lib/`
- [x] Create the following files:
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

**Pull Request:**  
[#9 Project Structure](https://github.com/o92design/raylib_svea/pull/9)  
***Description:***  
This pull request includes the addition of a comprehensive `Makefile` for building the project and documentation files for the directory structure.

---

For more details, visit the [issues page](https://github.com/o92design/raylib_svea/issues?q=is%3Aissue).