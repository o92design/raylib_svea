#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "game_initialize.h"
#include "game_render.h"
#include "components/sprite_component.h"

// Test function to verify game rendering
void test_game_render(void) {
    CU_ASSERT(initialize_game() == 0);

    // Create a texture component
    SpriteComponent spriteComponent;
    spriteComponent.sprite = LoadTexture("res/viking.png");
    CU_ASSERT(spriteComponent.sprite.id == 0);

    // Render the game (this is a placeholder, actual rendering tests would be more complex)
    render_game();

    // Cleanup
    UnloadTexture(spriteComponent.sprite);
    CU_ASSERT(cleanup_game() == 0);
}
