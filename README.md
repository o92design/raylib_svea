# Svea Rike 2 Clone

## Battle Mechanics

1. **Unit Types**:
    - **Infantry**: Basic troops with balanced attack and defense values.
    - **Cavalry**: Units with high attack but lower defense.
    - **Artillery**: Automatically placed units based on the number of units.

## Phases of the Game

1. **Preparation Phase**:
    - **Unit Placement**: The player places their units on the battlefield. Artillery is automatically placed based on the number of units.
    - **Strategic Planning**: The player can review the battlefield and plan their moves.

2. **Battle Phase**:
    - **Turn Order**: The player and the enemy take turns acting. Each unit gets one action per turn.
    - **Actions per Turn**:
        - **Attack**: A unit can attack an enemy within range (if an enemy is in the direction the unit moves).
        - **Counter-Attack**: A unit that is attacked by an enemy and does not die automatically performs a counter-attack.
        - **Move**: A unit can move to a nearby position (up, down, left, right).
    - **Damage Calculation**: Damage is calculated based on the attacker's attack value minus the defender's defense value.

3. **Result Phase**:
    - **End of Battle**: The battle ends when all units on one side are defeated or if a unit reaches the other side (which results in an automatic win for that side).
    - **Result**: Display the result of the battle (win, loss, or draw).
    - **Rewards**: The player receives rewards based on the outcome, such as resources or experience points.

4. **Post-Battle Phase**:
    - **Recovery**: The player can recover their units and prepare for the next battle.
    - **Upgrades**: The player can upgrade their units or purchase new units based on the rewards received.

## Graphics and UI

1. **Battlefield**:
    - **Grid**: Use a grid to represent the battlefield, with circles as graphical elements.

2. **Unit Representation**:
    - **Icons**: Use icons to represent different unit types.
    - **Health Bars**: Display a health bar above each unit to indicate its current health.

3. **User Interface**:
    - **Movement**: The selected unit gets arrows indicating the directions it can move.
    - **Information**: Display information about the selected unit and enemy units.

## [Development Plan](DEVELOPMENT_PLAN.md)

## [Architecture](ARCHITECTURE.md)