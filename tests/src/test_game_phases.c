#include <CUnit/CUnit.h>
#include "game_phase.h"
#include "game_loop.h"
#include "game_initialize.h"

// Test phase transitions
void test_phase_transitions(void) {
    CU_ASSERT(initialize_game() == 0);

    CU_ASSERT(get_current_phase() == PHASE_PREPARATION);

    // Test all phase transitions
    switch_phase(PHASE_BATTLE);
    CU_ASSERT(get_current_phase() == PHASE_BATTLE);

    switch_phase(PHASE_RESULT);
    CU_ASSERT(get_current_phase() == PHASE_RESULT);

    switch_phase(PHASE_POST_BATTLE);
    CU_ASSERT(get_current_phase() == PHASE_POST_BATTLE);

    switch_phase(PHASE_PREPARATION);
    CU_ASSERT(get_current_phase() == PHASE_PREPARATION);

    cleanup_game();
}