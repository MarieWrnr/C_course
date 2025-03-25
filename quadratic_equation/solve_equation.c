#include "solve_equation.h"
#include "floating_arithmetic.h"
#include "equation.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// backend functions | for solving equation 

// TODO: static?
equation_type define_equation_type(float a, float b) {
    bool is_a_zero = is_equal(a, 0);
    bool is_b_zero = is_equal(b, 0);

	if (is_a_zero) {
        return is_b_zero ? NO_EQUATION_TYPE : LINEAR_EQUATION;
    }
    return QUADRATIC_EQUATION;
}

// TODO: static?
float calculate_discriminant(float a, float b, float c) { 
    return b * b - 4 * a * c;
}

// TODO: static?
equation_solution solve_linear_equation(equation *data) {
    equation_solution linear_solution;
    float b = data->b;
    float c = data->c;

    linear_solution.roots[0] = -c / b;
    linear_solution.type = ONE_LINEAR_ROOT;

    return linear_solution;
}

equation_solution solve_quadratic_equation(equation *data) {
    equation_solution quadratic_solution = {};
    float a = data->a;
    float b = data->b;
    float c = data->c;

    quadratic_solution.D = calculate_discriminant(a, b, c);

    if (is_equal(quadratic_solution.D, 0)) { // D = 0
        quadratic_solution.roots[0] = -b / (2 * a);
        quadratic_solution.type = ONE_QUADRATIC_ROOT;
    }

   
    else if (quadratic_solution.D > 0) {
        float sqrtf_D = sqrtf(quadratic_solution.D);
        quadratic_solution.roots[0] = (-b + sqrtf_D) / (2 * a); 
        quadratic_solution.roots[1] = (-b - sqrtf_D) / (2 * a);
        quadratic_solution.type = TWO_ROOTS;
    }

    else {
        quadratic_solution.type = NO_REAL_ROOTS;
    }

    return quadratic_solution;
}

equation_solution solve_equation(equation *data) {
    equation_solution solution = {};
    data->type = define_equation_type(data->a, data->b); // Saving equation type

    switch(data->type) { // Choosing how to solve the equation
        case QUADRATIC_EQUATION:
            solution = solve_quadratic_equation(data); 
            break;

        case LINEAR_EQUATION:
            solution = solve_linear_equation(data);
            break;

        case NO_EQUATION_TYPE: // TODO: add brackets { around declaration to make it compile without C23 extension
            // TODO: solve_constant_equation(data); // ?
            bool is_c_zero = is_equal(data->c, 0);

            if (is_c_zero) {
                solution.type = INFINITE_ROOTS;
            }

            else {
                solution.type = NO_ANY_ROOTS;
            }

            break;

        default:
            assert(false && "Unhandled equation type");
            break;
    } 

    approximate_to_zero(&solution.roots[0]);
    approximate_to_zero(&solution.roots[1]);
    
    return solution;
}
