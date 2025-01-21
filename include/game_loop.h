#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "game_phase.h"

GAME_PHASE get_current_phase(void);
void handle_phase_transition(void);
void switch_phase(GAME_PHASE p_phase);
int run_game_loop(void);

#endif // GAME_LOOP_H