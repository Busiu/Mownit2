//
// Created by Busiu on 02.12.2018.
//

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

double NumericIntegrator::monteCarloMethod(double a, double b, int noSamples, std::function <double(double)> f)
{
    double totalArea = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(a, b);
    for(int i = 0; i < noSamples; i++)
    {
        double x0 = dis(gen);
        double tmpArea = f(x0) * (b - a);
        totalArea += tmpArea;
    }

    return totalArea / noSamples;
}

double NumericIntegrator::monteCarloPI(int noSamples)
{
    int innerSamples = 0;
    double radius = 1.0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, radius);
    for(int i = 0; i < noSamples; i++)
    {

        double x = dis(gen);
        double y = dis(gen);
        if(sqrt(x*x + y*y) <= radius)
        {
            innerSamples++;
        }
    }

    return 4.0 * innerSamples / noSamples;
}