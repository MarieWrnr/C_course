#include "../floating_arithmetic.h"
// работа с аргументами переменной длины (когда их количество меняется)
#include <stdarg.h>
// for working with NULL Objects
#include <stddef.h>
// exception handling
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>

// bool test_false() {
//     return false;
// }

static void test_are_coefficients_infinity(void **state) {
    (void) state;

    /*TEST FORMAT
    1. All numbers are real
    2. One of coefficients equals to INFINITY
    3. One of coefficients equals to -INFINITY
    4. All the coefficients equal to INFINITY
    5. One of coefficients is NaN
    */

    // TODO: make each test case more visible, e.g.
    //
    // struct test_cases {
    //     float a;
    //     float b;
    //     float c;
    // } tests[] = {
    //     { .a = 5.0, .b = 2.0, .c = 1.0 },
    //     { .a = 5.0, .b = 2.0, .c = 1.0 },
    //     { .a = 5.0, .b = 2.0, .c = 1.0 },
    //     { .a = 5.0, .b = 2.0, .c = 1.0 },
    //     { .a = 5.0, .b = 2.0, .c = 1.0 },
    // };

    float a_values[] = {5.0, INFINITY, 5.0, INFINITY, NAN};
    float b_values[] = {2.0, 2.0, -INFINITY, INFINITY, 2.0};
    float c_values[] = {1.0, 1.0, 1.0, INFINITY, 1.0};
    bool expected_results[] = {false, true, true, true, false};

    size_t num_cases = sizeof(expected_results) / sizeof(expected_results[0]);

    //assert_true(test_false());
    // TODO: try to make it compile without warnings
    for (int i = 0; i < num_cases; i++) {
        assert_int_equal(are_coefficients_infinity(a_values[i], b_values[i], c_values[i]), expected_results[i]);
    }
}
