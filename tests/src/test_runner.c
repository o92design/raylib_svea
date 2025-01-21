#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "include/suites/test_suites.h"

int main() {
    CU_initialize_registry();

    // Lägg till en suite för varje testfil
    // CU_pSuite example_suite = CU_add_suite("Example Suite", 0, 0);
    // CU_add_test(example_suite, "Example Test", test_example);

    CU_pSuite component_system_suite = CU_add_suite("Component System Suite", 0, 0);
    CU_add_test(component_system_suite, "Test Component Memory Management", test_component_memory_management);
    CU_add_test(component_system_suite, "Test Add Components", test_add_components);

    CU_pSuite game_initialize_suite = CU_add_suite("Game Initialize Suite", 0, 0);
    CU_add_test(game_initialize_suite, "Test Game Initialization", test_game_initialize);
    CU_add_test(game_initialize_suite, "Test Game Cleanup Without Initialization", test_game_cleanup_without_initialize);
    
    CU_pSuite sprite_loader_suite = CU_add_suite("Sprite Loader Suite", 0, 0);
    CU_add_test(sprite_loader_suite, "Test Load and Unload Sprites", test_load_and_unload_sprites);
    
    CU_pSuite game_render_suite = CU_add_suite("Game Render Suite", 0, 0);
    CU_add_test(game_render_suite, "Test Game Rendering", test_game_render);

    CU_pSuite game_phase_suite = CU_add_suite("Game Phase Suite", 0, 0);
    CU_add_test(game_phase_suite, "Test Phase Transitions", test_phase_transitions);
    
    CU_pSuite clickable_component_suite = CU_add_suite("Clickable Component Suite", 0, 0);
    CU_add_test(clickable_component_suite, "Test Clickable Component", test_clickable_component);

/** 
    CU_pSuite game_loop_suite = CU_add_suite("Game Loop Suite", 0, 0);
    CU_add_test(game_loop_suite, "Test Game Loop Execution", test_game_loop);
*/    

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    return 0;
}
