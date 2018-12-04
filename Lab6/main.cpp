//
// Created by Busiu on 01.12.2018.
//

#include <iostream>
#include <math.h>

#include "NumericIntegrator.hpp"

int main(void)
{
    std::cout << "Lab 6" << std::endl;

    //  Inizjalizacja   ------------------------------------------------------------------------------------------------
    NumericIntegrator integrator;

    std::function <double(double)> linear = [](double x) { return 3*x; };
    std::function <double(double)> quadratic = [](double x) { return 5*x*x - 7*x + 4; };
    std::function <double(double)> cubic = [](double x) { return x*x*x - 6*x*x + 2*x - 10; };
    std::function <double(double)> exponential = [](double x) { return std::pow(M_E, x); };
    std::function <double(double)> sinusoidal = [](double x) { return sin(x); };

    //  Zadanie 1   ----------------------------------------------------------------------------------------------------

    std::cout << "Funkcja Liniowa: " << std::endl;
    std::cout << "\tMetoda Prostokatow: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.rectangleMethod(0, 10, 3*i, linear) << std::endl;
    }
    std::cout << "\tMetoda Trapezow: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.trapeziumMethod(0, 10, 3*i, linear) << std::endl;
    }
    std::cout << "\tMetoda Simpsona: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.simpsonMethod(0, 10, 3*i, linear) << std::endl;
    }

    std::cout << "Funkcja Kwadratowa: " << std::endl;
    std::cout << "\tMetoda Prostokatow: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.rectangleMethod(0, 10, 3*i, quadratic) << std::endl;
    }
    std::cout << "\tMetoda Trapezow: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.trapeziumMethod(0, 10, 3*i, quadratic) << std::endl;
    }
    std::cout << "\tMetoda Simpsona: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.simpsonMethod(0, 10, 3*i, quadratic) << std::endl;
    }

    std::cout << "Funkcja Szescienna: " << std::endl;
    std::cout << "\tMetoda Prostokatow: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.rectangleMethod(0, 10, 3*i, cubic) << std::endl;
    }
    std::cout << "\tMetoda Trapezow: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.trapeziumMethod(0, 10, 3*i, cubic) << std::endl;
    }
    std::cout << "\tMetoda Simpsona: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.simpsonMethod(0, 10, 3*i, cubic) << std::endl;
    }

    std::cout << "Funkcja Eksponencjalna: " << std::endl;
    std::cout << "\tMetoda Prostokatow: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.rectangleMethod(0, 10, 3*i, exponential) << std::endl;
    }
    std::cout << "\tMetoda Trapezow: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.trapeziumMethod(0, 10, 3*i, exponential) << std::endl;
    }
    std::cout << "\tMetoda Simpsona: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.simpsonMethod(0, 10, 3*i, exponential) << std::endl;
    }

    std::cout << "Funkcja Sinusoidalna: " << std::endl;
    std::cout << "\tMetoda Prostokatow: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.rectangleMethod(0, 10, 3*i, sinusoidal) << std::endl;
    }
    std::cout << "\tMetoda Trapezow: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.trapeziumMethod(0, 10, 3*i, sinusoidal) << std::endl;
    }
    std::cout << "\tMetoda Simpsona: " << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.simpsonMethod(0, 10, 3*i, sinusoidal) << std::endl;
    }

    //  Zadanie 3   ----------------------------------------------------------------------------------------------------

    std::cout << "Wyliczanie liczby PI za pomoca metody Monte Carlo: " << std::endl;
    for(int i = 1; i <= 100; i++)
    {
        std::cout << "\t" << integrator.monteCarloPI(100 * i) << "," << std::endl;
    }

    //  Zadanie 4   ----------------------------------------------------------------------------------------------------

    std::cout << "Wyliczanie pol pod wykresami poprzednich funkcji za pomoca metody Monte Carlo: " << std::endl;

    std::cout << "\tFunkcja Liniowa:" << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.monteCarloMethod(0, 10, 100 * i, linear) << std::endl;
    }
    std::cout << "\tFunkcja Kwadratowa:" << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.monteCarloMethod(0, 10, 100 * i, quadratic) << std::endl;
    }
    std::cout << "\tFunkcja Szescienna:" << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.monteCarloMethod(0, 10, 100 * i, cubic) << std::endl;
    }
    std::cout << "\tFunkcja Eksponencjalna:" << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.monteCarloMethod(0, 10, 100 * i, exponential) << std::endl;
    }
    std::cout << "\tFunkcja Sinusoidalna:" << std::endl;
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "\t\t" << integrator.monteCarloMethod(0, 10, 100 * i, sinusoidal) << std::endl;
    }

}