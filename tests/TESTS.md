# Tests

This directory contains the unit tests for the project. We use the CUnit framework for writing and running tests. The tests are organized to ensure that all components and systems of the game are functioning correctly.

We use the [CUnit](http://cunit.sourceforge.net/) framework

## Directory Structure

- `src/`: Contains the source files for the tests.
- `test_example.c`: An example test file to demonstrate how to write tests using CUnit.

## Writing Tests

To write a new test, follow these steps:

1. **Create a new test file**:
    - Create a new `.c` file in the `src/` directory. For example, `src/test_new_feature.c`.

2. **Include necessary headers**:
    - Include the CUnit headers and any other headers required for the tests.
    ```c
    #include <CUnit/CUnit.h>
    #include <CUnit/Basic.h>
    #include "path/to/your/header.h"
    ```

3. **Write test functions**:
    - Write functions that contain the test cases. Each function should use CUnit assertions to verify the expected behavior.
    ```c
    void test_example(void) {
        CU_ASSERT(2 + 2 == 4);
    }
    ```

4. **Register the test functions**:
    - In the `main` function, register the test functions with CUnit and run the tests.
    ```c
    int main() {
        CU_initialize_registry();
        CU_pSuite suite = CU_add_suite("Example Suite", 0, 0);
        CU_add_test(suite, "Example Test", test_example);
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        CU_cleanup_registry();
        return 0;
    }
    ```

## Running Tests

To build and run the tests, use the following commands:

1. **Build the tests**:
    ```sh
    make tests
    ```

2. **Run the tests**:
    ```sh
    make test
    ```

The test results will be displayed in the terminal. Ensure that all tests pass before committing your changes.

## Example Test File

Here is an example test file to get you started:

```c
// filepath: tests/src/test_example.c
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