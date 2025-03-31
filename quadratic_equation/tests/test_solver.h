#ifndef TEST_SOLVER_H
#define TEST_SOLVER_H
#include "solve_equation.h"

// For solve_quadratic/linear_equation, define_equation_type, solve_equation etc.
typedef struct {
    float a, b, c;     // B can't be equal to 0
    float D;
    equation_type type;
    roots_type root_type;
    float root1, root2;
} EquationTestCases;


void test_are_coefficients_infinity(void **state);
void test_define_equation_type(void **state);
void test_solve_linear_equation(void **state); 
void test_solve_quadratic_equation(void **state); 
#endif