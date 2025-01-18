#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_example(void) {
    CU_ASSERT(2 + 2 == 4);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Example Suite", 0, 0);
    CU_add_test(suite, "Example Test", test_example);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}