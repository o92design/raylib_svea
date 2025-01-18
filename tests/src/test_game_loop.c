#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "game_initialize.h"
#include "game_loop.h"

// Test function to verify game loop execution
void test_game_loop(void) {
    CU_ASSERT(initialize_game() == 0);
    CU_ASSERT(run_game_loop() == 0);
    CU_ASSERT(cleanup_game() == 0);
}