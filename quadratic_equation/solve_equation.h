#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

#include "equation.h"
#include <stdbool.h>

bool are_coefficients_infinity (float a, float b, float c);

equation_solution solve_equation(equation *data);

#endif