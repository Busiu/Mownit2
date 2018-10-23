//
// Created by Busiu on 20.10.2018.
//

#include "LinearRegressor.hpp"

void LinearRegressor::fit(const std::vector<float>& x, const std::vector<float>& y)
{
    int noPointsX = x.size();
    int noPointsY = y.size();
    if (noPointsX != noPointsY) {
        std::cout << "Given vectors have different number of elements!" << std::endl;
        return;
    }

    float a;
    float b;
    float sumX = 0;
    float sumY = 0;
    float sumXX = 0;
    float sumYY = 0;
    float sumXY = 0;
    int noPoints = noPointsX;
    for(int i = 0; i < noPoints; i++)
    {
        sumX += x[i];
        sumY += y[i];
        sumXX += x[i] * x[i];
        sumYY += y[i] * y[i];
        sumXY += x[i] * y[i];
    }

    a = ((noPoints * sumXY - sumX * sumY) / (noPoints * sumXX - sumX * sumX));
    b = ((sumY - a * sumX) / (noPoints));

    coefficients.first = a;
    coefficients.second = b;
}

std::vector<float> LinearRegressor::predict(const std::vector<float>& x)
{
    int noPoints = x.size();
    std::vector<float> result;
    for(int i = 0; i < noPoints; i++)
    {
        result.push_back(coefficients.first * x[i] + coefficients.second);
    }

    return result;
}

std::pair<float, float> LinearRegressor::getCoefficients()
{
    return coefficients;
};


