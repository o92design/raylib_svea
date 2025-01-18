#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "game_initialize.h"
#include "game_render.h"
#include "components/sprite_component.h"
#include "systems/sprite_loader_system.h"

// Test function to verify game rendering
void test_game_render(void) {
    // Initialize the game
    CU_ASSERT(initialize_game() == 0);

    int numberOfSprites = 1;
    // Create an array of sprite components
    SpriteComponent spriteComponents[numberOfSprites];
    spriteComponents[0] = load_sprite("res/img/viking.png");

    // Check that the sprite is loaded correctly
    CU_ASSERT(spriteComponents[0].sprite.id != 0);

    // Render the game (this is a placeholder, actual rendering tests would be more complex)
    render_game(spriteComponents, numberOfSprites);

    // Cleanup
    unload_sprites(spriteComponents, numberOfSprites);
    CU_ASSERT(cleanup_game() == 0);
}