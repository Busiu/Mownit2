//
// Created by Busiu on 20.10.2018.
//

#include <cmath>
#include "Enumerator.hpp"

float Enumerator::rmse(std::vector<float> x, std::vector<float> y)
{
    int noPointsX = x.size();
    int noPointsY = y.size();
    if(noPointsX != noPointsY)
    {
        std::cout << "Given vectors have different number of elements!" << std::endl;
        return -1;
    }

    int noPoints = noPointsX;
    float result = 0.0f;
    for(int i = 0; i < noPoints; i++)
    {
        result += pow((x[i] - y[i]), 2);
    }

    return result;
}

std::pair<float,float> Enumerator::linearRegression(std::vector<float> x, std::vector<float> y)
{
    int noPointsX = x.size();
    int noPointsY = y.size();
    if(noPointsX != noPointsY)
    {
        std::cout << "Given vectors have different number of elements!" << std::endl;
        return std::make_pair(-1, -1);
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

    return std::make_pair(a, b);

}


