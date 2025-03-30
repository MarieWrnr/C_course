// TODO: read about IEEE754 standard for representing floating point numbers


#include "floating_arithmetic.h"
#include <stdbool.h>
#include <math.h>

const float epsilon = 1e-6; 

bool is_equal(float num1, float num2) {
    float res = fabs(num1 - num2);
    return res <= epsilon;
}

void approximate_to_zero(float* num) {
    if (is_equal(*num, 0))  {  // to cut off approximate part and "-" sign (like -0.0000000000000001 ~= 0.0)
        *num = 0;
    }
}
