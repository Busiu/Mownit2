//
// Created by Busiu on 02.12.2018.
//

#include <chrono>
#include <thread>
#include "NumericIntegrator.hpp"

double NumericIntegrator::rectangleMethod(double a, double b, int noRange, std::function <double(double)> f)
{
    double area = 0;
    double chunk = (b - a) / noRange;
    for(int i = 1; i <= noRange; i++)
    {
        area += (chunk * f(a + chunk * i));
    }

    return area;
}

double NumericIntegrator::trapeziumMethod(double a, double b, int noRange, std::function <double(double)> f)
{
    double area = 0;
    double chunk = (b - a) / noRange;
    for(int i = 0; i < noRange; i++)
    {
        double fx0 = f(a+chunk*i);
        double fx1 = f(a+chunk*(i+1));
        area += ((fx0 + fx1) * chunk / 2);
    }

    return area;
}

double NumericIntegrator::simpsonMethod(double a, double b, int noRange, std::function <double(double)> f)
{
    double area = 0;
    double chunk = (b - a) / noRange;
    for(int i = 0; i < noRange; i++)
    {
        double fx0 = f(a+chunk*i);
        double fx1 = f(a+chunk*(i+0.5));
        double fx2 = f(a+chunk*(i+1));
        area += ((chunk / 6) * (fx0 + 4*fx1 + fx2));
    }

    return area;
}

double NumericIntegrator::monteCarloPI(int noSamples)
{
    int innerSamples = 0;
    for(int i = 0; i < noSamples; i++)
    {
        std::default_random_engine generator(static_cast<unsigned> (time(nullptr) * clock()));
        std::uniform_real_distribution<double> distributionOfX{-50, 50};
        std::uniform_real_distribution<double> distributionOfY{-50, 50};
        double x = distributionOfX(generator);
        double y = distributionOfY(generator);
        if(x*x + y*y > 2500)
        {
            continue;
        }
        else
        {
            innerSamples++;
        }

        std::chrono::duration<int, std::micro> timespan(1000);
        std::this_thread::sleep_for(timespan);
    }

    return 4.0 * innerSamples / noSamples;
}

