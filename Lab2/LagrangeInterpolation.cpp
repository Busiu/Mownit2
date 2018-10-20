//
// Created by Busiu on 17.10.2018.
//

#include "LagrangeInterpolation.hpp"

LagrangeInterpolation::LagrangeInterpolation(const PointsList1D& points) :
        pointsList1D(points)
        {}

void LagrangeInterpolation::Interpolate1D(int pointsToInterpolate) {
    std::vector<int> index(pointsToInterpolate);
    std::vector<float> tx;

    int i = 0;
    int points_size = pointsList1D.size() - 1;
    std::generate(index.begin(), index.end(), [&i, &pointsToInterpolate, &points_size, &tx]() {
        float percent = ((float) i) / (float(pointsToInterpolate - 1));
        tx.push_back((points_size) * percent);
        return int(tx[i++]);
    });

    std::cout << "Lagrange Interpolation 1D:" << std::endl;
    for (int i = 0; i < pointsToInterpolate; i++)
    {
        float y = calculateLagrange(tx[i]);

        std::cout << "Value at " << tx[i] << " = " << y << std::endl;
    }

    std::cout << std::endl;
}
void LagrangeInterpolation::Interpolate2D(int pointsToInterpolate)
{
    std::cout << "Ni mo xD" << std::endl;
}

float LagrangeInterpolation::calculateLagrange(float x)
{
    float result = 0;
    int noPoints = pointsList1D.size();

    for(int i = 0; i < noPoints; i++)
    {
        float component = pointsList1D[i];
        for(int j = 0; j < noPoints; j++)
        {
            if(i != j)
            {
                component *= ((x - j) / (i - j));
            }
        }

        result += component;
    }

    return result;
}
