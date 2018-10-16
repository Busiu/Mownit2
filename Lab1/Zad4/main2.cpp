//
// Created by Busiu on 16.10.2018.
//

#include <iostream>
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf_gamma.h>

float unstable_difference(float a, float b)
{
    float left = a + b;
    float right = a - b;
    float result = left * right;

    return result;
}

float stable_difference(float a, float b)
{
    float left = a * a;
    float right = b * b;
    float result = left - right;

    return result;
}

int main ()
{
    std::cout << unstable_difference(10.0001, 10.00) << std::endl;
    std::cout << stable_difference(10.0001, 10.00) << std::endl;
    return 0;
}