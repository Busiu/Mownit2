//
// Created by Busiu on 14.10.2018.
//

#include <iostream>
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf_gamma.h>

double unstable_exponential(double exponent, int accuracy)
{
    double result = 1.0;

    for(unsigned int i = 1; i <= accuracy; i++)
    {
        double pow = gsl_pow_int(exponent, i);
        auto factorial = static_cast<long long int> (gsl_sf_fact(i));
        double component = pow / factorial;
        result += component;
    }

    return result;
}

double stable_exponential(double exponent, int accuracy)
{
    double denominator = unstable_exponential(-exponent, accuracy);

    return 1.0 / denominator;
}

int main ()
{
    std::cout << unstable_exponential(-5, 25) << std::endl;
    std::cout << stable_exponential(-5, 25) << std::endl;
    return 0;
}
