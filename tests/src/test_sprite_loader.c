#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "game_initialize.h"
#include "components/sprite_component.h"
#include "systems/sprite_loader_system.h"

// Test function to verify loading and unloading of sprites
void test_load_and_unload_sprites(void) {
    // Initialize the game
    CU_ASSERT(initialize_game() == 0);

    // Create an array of sprite components
    SpriteComponent spriteComponents[3];
    spriteComponents[0] = load_sprite("res/img/viking.png");
    spriteComponents[1] = load_sprite("res/img/viking.png");
    spriteComponents[2] = load_sprite("res/img/viking.png");

    // Check that all sprites are loaded correctly
    for (int i = 0; i < 3; i++) {
        CU_ASSERT(spriteComponents[i].sprite.id != 0);
    }

    // Unload the second sprite
    CU_ASSERT(unload_sprite(spriteComponents, 1) == 0);

    // Check that the second sprite is unloaded and others are still valid
    CU_ASSERT(spriteComponents[0].sprite.id != 0);
    CU_ASSERT(spriteComponents[1].sprite.id == 0);
    CU_ASSERT(spriteComponents[2].sprite.id != 0);

    // Cleanup remaining sprites
    CU_ASSERT(unload_sprites(spriteComponents, 3) == 0);
    CU_ASSERT(cleanup_game() == 0);
}