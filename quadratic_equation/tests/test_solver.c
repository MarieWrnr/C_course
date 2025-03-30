#include "test_solver.h"
#include "solve_equation.h"
#include <cmocka.h>
#include <math.h>

void test_are_coefficients_infinity(void **state) {
    (void) state;

    /*TEST FORMAT
    1. All numbers are real
    2. One of coefficients equals to INFINITY
    3. One of coefficients equals to -INFINITY
    4. All the coefficients equal to INFINITY
    5. One of coefficients is NaN
    */

    struct test_cases {
        float a, b, c;
        bool expected;
    } tests[] = {
        { .a = 5.0, .b = 2.0, .c = 1.0, .expected = false},
        { .a = 5.0, .b = INFINITY, .c = 1.0, .expected = true },
        { .a = 5.0, .b = 2.0, .c = -INFINITY, .expected = true },
        { .a = INFINITY, .b = INFINITY, .c = INFINITY, .expected = true },
        { .a = 5.0, .b = NAN, .c = 1.0, .expected = false},
    };

    size_t num_cases = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < num_cases; i++) {
        print_message("[ INDEX    ] = %zu\n", i);
        assert_int_equal(are_coefficients_infinity(tests[i].a, tests[i].b, tests[i].c), tests[i].expected);
    }
}
