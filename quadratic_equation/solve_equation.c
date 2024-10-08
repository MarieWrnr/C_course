#include "solve_equation.h"
//#include "recording_errors.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

const float epsilon = 1e-6;

// backend functions | for solving equation 
bool is_equal(float num1, float num2) { // TODO: переименовать в  is_equal;
    float res = fabs(num1 - num2);
    return res <= epsilon;
}


float linear_solution(float b, float c) {
    return -c / b;
}

int quadratic_solution(float a, float b, float c, float solutions[], NoSolutionCases* solution_case) { 
    // TODO: структура Errors (код ошибки, текст), структура первичных данных (коэф-ты), структура для решения | подумать над возвращаемым типом
    float D = (b*b) - (4 * a * c);
    //printf("%f D %f D - 0.0\n", D, D - 0.0);
    
    if (D > 0) {
        float sqrtf_D = sqrtf(D);
        solutions[0] = (-b + sqrtf_D) / (2 * a); 
        solutions[1] = (-b - sqrtf_D) / (2 * a);

        if (is_equal(solutions[0], 0))  {  // to cut off approximate part and "-" sign (like -0.0000000000000001 ~= 0.0)
            solutions[0] = 0;
        }
        if (is_equal(solutions[1], 0))  {
            solutions[1] = 0;
        }

        return 2;
    }

    else if (is_equal(D, 0)) {
        solutions[0] = -b / (2 * a);
        if (is_equal(solutions[0], 0))  { // TODO: вынести в отдельную функцию 
            solutions[0] = 0;
        }
        return 1;
    }

    *solution_case = NEGATIVE_DISCRIMINANT;
    //printf("D = %.2f;\n", D); // перенести в описательную часть
    return 0;
}

int solve_equation(float a, float b, float c, float solutions[], NoSolutionCases* solution_case) {

    if (is_equal(a, 0)) { 
        if (is_equal(b, 0)) { // two "if" is enough to make a conclusion that equation has no roots
            *solution_case = NO_COEFFICIENTS;
            return 0;
        }

        printf("That equation is linear!\n"); // TODO ME: вынести в описательную часть
        solutions[0] = linear_solution(b, c);
        return 1;
    }
    
    return quadratic_solution(a, b, c, solutions, solution_case);
}
