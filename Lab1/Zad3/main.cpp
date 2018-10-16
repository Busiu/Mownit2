#include <iostream>
#include <gsl/gsl_ieee_utils.h>

int main ()
{
    float number = 1024;

    for(int i = 0; i < 256; i++)
    {
        std::cout << "Liczba = ";
        gsl_ieee_printf_float(&number);
        std::cout << std::endl;

        number /= 2;
    }

    return 0;
}
