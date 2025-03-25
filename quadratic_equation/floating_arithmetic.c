// TODO: read about IEEE754 standard for representing floating point numbers


#include "floating_arithmetic.h"
#include <stdbool.h>
#include <math.h>

const float epsilon = 1e-6; 

// TODO: doesn't feel like general-purspose floating arithmetic
//       I consider this to be part of equation solver's contract, so it really should be moved there
bool are_coefficients_infinity (float a, float b, float c) {
    //  общая проверка на бесконечность
    return isinf(a) || isinf(b) || isinf(c); 
}

bool is_equal(float num1, float num2) {
    float res = fabs(num1 - num2);
    return res <= epsilon;
}

void approximate_to_zero(float* num) {
    if (is_equal(*num, 0))  {  // to cut off approximate part and "-" sign (like -0.0000000000000001 ~= 0.0)
        *num = 0;
    }
}
