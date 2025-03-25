#include "equation.h"
#include "solve_equation.h"
#include "user_interface.h"
#include <stdio.h>

// TODO: try to write docs using Doxygen
// TODO: try to write automatic tests (you can do it fully on your own or you can use googletest)

int main () {
    equation data = {};
    
    read_coefficients(&data);  
    equation_solution solution = solve_equation(&data);
    print_solution(&data, &solution);

    return 0;
}