#include "test_arithmetic.h"
#include "test_solver.h"
#include <cmocka.h>


const struct CMUnitTest solver_tests[] = {
    cmocka_unit_test(test_are_coefficients_infinity),
};

const struct CMUnitTest floating_arithmetic_tests[] = {
    cmocka_unit_test(test_is_equal),
    cmocka_unit_test(test_approximate_to_zero),
};

int main(void) {
    int status = 0;
    status += cmocka_run_group_tests(floating_arithmetic_tests, NULL, NULL);
    status += cmocka_run_group_tests(solver_tests, NULL, NULL);
    return status;
}
