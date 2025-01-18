# Issues for raylib_svea

## Open Issues

### [Set Up Test-Driven Development Environment](https://github.com/o92design/raylib_svea/issues/8)
**Description:**  
Set up the environment for test-driven development (TDD) by configuring the necessary tools and writing initial tests.

**Progress:** In Progress

**Acceptance Criteria:**
- [x] Install and configure a unit testing framework (CUnit).
- [x] Create a directory for tests (e.g., `tests/`).
- [x] Write basic initial unit tests for checking that it works.
- [x] Integrate unit tests into the build process using the `Makefile`.

---

### [Implement Entity and Component Management](https://github.com/o92design/raylib_svea/issues/7)
**Description:**  
Implement the basic entity and component management system to manage game entities and their components.

**Progress:** Open

**Acceptance Criteria:**
- [ ] Create an entity system to manage game entities.
- [ ] Ensure that entities can be created, updated, and destroyed.
- [ ] Implement a basic component system to manage components.
- [ ] Ensure that components can be added to and removed from entities.

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

**Progress:** Open

**Acceptance Criteria:**
- [ ] Implement functionality to register mouse clicks.
- [ ] Determine if the player is clicking on an entity or a specific area of the screen.

---

### [Implement Phase Transitions](https://github.com/o92design/raylib_svea/issues/4)
**Description:**  
Implement the ability to transition between the different phases of the game (Preparation Phase, Battle Phase, Result Phase, Post-Battle Phase).

**Progress:** Open

**Acceptance Criteria:**
- [ ] Implement the ability to transition from the Preparation Phase to the Battle Phase.
- [ ] Implement the ability to transition from the Battle Phase to the Result Phase.
- [ ] Implement the ability to transition from the Result Phase to the Post-Battle Phase.
- [ ] Implement the ability to transition from the Post-Battle Phase to the Preparation Phase.

---

### [Implement Basic Rendering](https://github.com/o92design/raylib_svea/issues/3)
**Description:**  
Implement basic rendering using Raylib to display an image on the screen.

**Progress:** Open

**Acceptance Criteria:**
- [ ] Use Raylib to initialize a window.
- [ ] Load an image and display it on the screen.

---

### [Implement Basic Game Loop](https://github.com/o92design/raylib_svea/issues/2)
**Description:**  
Implement a basic game loop that runs continuously until the game is exited.

**Progress:** Open

**Acceptance Criteria:**
- [ ] Create a main file (`main.c`) that contains the game loop.
- [ ] Create a game loop files (`game_initialize.h` and `game_initialize.c`) that contains the game loop
- [ ] Create a game loop files (`game_loop.h` and `game_loop.c`) that contains the game loop
- [ ] Ensure the game loop runs continuously until the game is exited.

---

## Closed Issues

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

---

### [#1 Project Structure](https://github.com/o92design/raylib_svea/pull/9)
**Description:**  
This pull request includes the addition of a comprehensive `Makefile` for building the project and documentation files for the directory structure.

**Progress:** Closed

**Changes:**
- Added a new `Makefile` to manage the build process, including debug and release builds, and a clean target.
- Added documentation for the `include`, `lib`, and `src` directories.

---