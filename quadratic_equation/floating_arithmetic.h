#ifndef FLOATING_ARITHMETIC_H
#define FLOATING_ARITHMETIC_H
#include <stdbool.h>

extern const float epsilon; 

bool is_equal(float num1, float num2);

void approximate_to_zero(float* num);

#endif