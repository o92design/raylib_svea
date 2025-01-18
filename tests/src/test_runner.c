#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

// Deklarera testfunktionerna från dina testfiler
void test_example(void);
void test_game_initialize(void);
void test_game_cleanup_without_initialize(void);
void test_game_loop(void);

int main() {
    CU_initialize_registry();

    // Lägg till en suite för varje testfil
    CU_pSuite example_suite = CU_add_suite("Example Suite", 0, 0);
    CU_add_test(example_suite, "Example Test", test_example);

    CU_pSuite game_loop_suite = CU_add_suite("Game Loop Suite", 0, 0);
    CU_add_test(game_loop_suite, "Test Game Initialization", test_game_initialize);
    CU_add_test(game_loop_suite, "Test Game Cleanup Without Initialization", test_game_cleanup_without_initialize);
    CU_add_test(game_loop_suite, "Test Game Loop Execution", test_game_loop);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}