#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

#include "equation.h"
#include <stdbool.h>

bool are_coefficients_infinity (float a, float b, float c);

// WARNING: я не знаю, как здесь лучше поступить

equation_type define_equation_type(float a, float b);

equation_solution solve_linear_equation(equation *data);

equation_solution solve_quadratic_equation(equation *data);

equation_solution solve_equation(equation *data);



#endif