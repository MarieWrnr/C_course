#include "test_arithmetic.h"
#include "floating_arithmetic.h"
#include <cmocka.h>
#include <math.h>


void test_approximate_to_zero(void **state) {
    (void) state;
    struct test_cases {
        float num;
        float expected;
    } tests[] = {
        {.num = 5, .expected = 5},
        {.num = 0.67, .expected = 0.67}, 
        {.num = 0.00000001, .expected = 0.0f},
        {.num = -0.00000001, .expected = 0.0f},
        {.num = 0.0f, .expected = 0.0f},
    };

    size_t num_cases = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < num_cases; i++) {
        print_message("[ INDEX    ] = %zu\n", i);
        approximate_to_zero(&tests[i].num);
        assert_float_equal(tests[i].num, tests[i].expected, epsilon);
    }

}


void test_is_equal(void **state) {
    (void) state;
    struct test_cases {
        float a, b;
        bool expected;
    } tests[] = {
        {.a = 5, .b = 0, .expected = false},
        {.a = 5, .b = 5, .expected = true},
        {.a = 0.67, .b = 0.677, .expected = false},
        {.a = 0.00000001, .b = 0.0000000101, .expected = true},
        {.a = -0.00000001, .b = -0.0000000101, .expected = true},
        {.a = 0, .b = 0.0001, .expected = false},
        {.a = -0.1, .b = -0.10001, .expected = false},
    };

    size_t num_cases = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < num_cases; i++) {
        print_message("[ INDEX    ] = %zu\n", i);
        assert_int_equal(is_equal(tests[i].a, tests[i].b), tests[i].expected);
    }
}