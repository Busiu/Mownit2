//
// Created by Busiu on 02.12.2018.
//

#ifndef MOWNIT2_NUMERICINTEGRATOR_HPP
#define MOWNIT2_NUMERICINTEGRATOR_HPP

#include <iostream>
#include <functional>
#include <random>
#include <time.h>

class NumericIntegrator {
private:

public:
    NumericIntegrator() = default;
    ~NumericIntegrator() = default;

    double rectangleMethod(double a, double b, int noRange, std::function <double(double)> f);
    double trapeziumMethod(double a, double b, int noRange, std::function <double(double)> f);
    double simpsonMethod(double a, double b, int noRange, std::function <double(double)> f);

    double monteCarloPI(int noSamples);
};


#endif //MOWNIT2_NUMERICINTEGRATOR_HPP
