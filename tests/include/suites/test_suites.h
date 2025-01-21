#ifndef TEST_SUITES_H
#define TEST_SUITES_H

// Example tests
void test_example(void);

// Game initialization tests
void test_game_initialize(void);
void test_game_cleanup_without_initialize(void);
void test_game_loop(void);

// Sprite system tests
void test_load_and_unload_sprites(void);
void test_game_render(void);

// Component system tests
void test_add_components(void);
void test_component_memory_management(void);

// Game phase tests
void test_phase_transitions(void);

#endif // TEST_SUITES_H