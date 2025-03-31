#include "test_solver.h"
#include "floating_arithmetic.h"
#include "equation.h"
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
        struct test_cases *test = &tests[i];
        print_message("[ INDEX    ] = %zu\n", i);
        assert_int_equal(are_coefficients_infinity(test->a, test->b, test->c), test->expected);
    }
}

void test_define_equation_type(void **state) {
    (void) state;

    /*TEST FORMAT
    1. A = 0 => bx + c = 0 => LINEAR_EQUATION
    2. BOTH A AND B EQUAL TO 0 => NO_EQUATION_TYPE (NOT SET)
    3. B = 0 => ax^2 + c = 0 => QUADRATIC_EQUATION
    4. BOTH A AND B NOT EQUAL TO 0 => ax^2 + bx + c = 0 => QUADRATIC_EQUATION
    5. B < 0 AND A = 0 => -bx + c = 0 => LINEAR_EQUATION
    6-7. A is getting closer to 0 (EPSILON = 1e-6) => NO_EQUATION_TYPE
    */

    EquationTestCases tests[] = {
        { .a = 0, .b = 4, .type = LINEAR_EQUATION},
        { .a = 0, .b = 0, .type = NO_EQUATION_TYPE},
        { .a = 4, .b = 0, .type = QUADRATIC_EQUATION},
        { .a = 4, .b = 4, .type = QUADRATIC_EQUATION},
        { .a = 0, .b = -4, .type = LINEAR_EQUATION},
        { .a = 1e-7, .b = 0, .type = NO_EQUATION_TYPE},
        { .a = -1e-7, .b = 0, .type = NO_EQUATION_TYPE},
    };

    size_t num_cases = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < num_cases; i++) {
        EquationTestCases *test = &tests[i];
        print_message("[ INDEX    ] = %zu\n", i);
        assert_int_equal(define_equation_type(test->a, test->b), test->type);
    }
}

void test_solve_linear_equation(void **data) {

    EquationTestCases tests[] = {
        {.b = 1, .c = 1, .root1 = -1},
        {.b = 1, .c = -1, .root1 = 1},
        {.b = 1, .c = 1e-7, .root1 = 0},
    };

    size_t num_cases = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < num_cases; i++) {
        EquationTestCases *test = &tests[i]; // Pointer to current testcase

        print_message("[ INDEX    ] = %zu\n", i);

        equation data = {.b = test->b, .c = test->c};
        equation_solution solution = solve_linear_equation(&data);

        //TODO: подписать проверки
        assert_int_equal(solution.type, ONE_LINEAR_ROOT);
        assert_float_equal(solution.roots[0], test->root1, epsilon);
    }
}

void test_solve_quadratic_equation(void **data) {

    EquationTestCases tests[] = {
        {.a = 1, .b = 4, .c = 3, .D = 4, .type = TWO_ROOTS, .root1 = -1, .root2 = -3},
    };

    size_t num_cases = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < num_cases; i++) {
        EquationTestCases *test = &tests[i]; // Pointer to current testcase
        
        print_message("[ INDEX    ] = %zu\n", i);

        equation data = {.a = test->a, .b = test->b, .c = test->c};
        equation_solution solution = solve_quadratic_equation(&data);

        //TODO: подписать проверки
        assert_float_equal(solution.D, test->D, epsilon);
        assert_int_equal(solution.type, test->type);
        assert_float_equal(solution.roots[0], test->root1, epsilon);
        assert_float_equal(solution.roots[1], test->root2, epsilon);
    }
}
