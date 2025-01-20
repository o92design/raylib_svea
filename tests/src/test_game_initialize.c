#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "game_initialize.h"

// Test function to verify game initialization
void test_game_initialize(void) {
    CU_ASSERT(initialize_game() == 0);
    CU_ASSERT(cleanup_game() == 0);
}

void test_game_cleanup_without_initialize(void) {
    CU_ASSERT(cleanup_game() == 0);
}