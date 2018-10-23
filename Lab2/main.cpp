//
// Created by Busiu on 17.10.2018.
//

#include "CubicInterpolation.hpp"
#include "LagrangeInterpolation.hpp"
#include "LinearRegressor.hpp"

#include "Enumerator.hpp"

int main(void)
{

    const PointsList1D points1D =
        {
                0.0f,
                1.6f,
                2.3f,
                3.5f,
                4.3f,
                5.9f,
                6.8f
        };
    const PointsList2D points2D =
        {
                { 0.0f, 1.1f },
                { 1.6f, 8.3f },
                { 2.3f, 6.5f },
                { 3.5f, 4.7f },
                { 4.3f, 3.1f },
                { 5.9f, 7.5f },
                { 6.8f, 0.0f }
        };
    const std::vector<float> x =
            {
                    0.0f,
                    1.0f,
                    2.0f,
                    3.0f,
                    4.0f,
                    5.0f,
                    7.0f,
                    9.0f,
                    11.0f,
                    14.0f
            };
    const std::vector<float> y =
            {
                    0.0f,
                    2.0f,
                    4.0f,
                    7.0f,
                    8.0f,
                    10.0f,
                    11.0f,
                    12.0f,
                    23.0f,
                    23.0f
            };


    auto cubicInterpolation = CubicInterpolation(points2D, points1D);
    auto lagrangeInterpolation = LagrangeInterpolation(points1D);

    cubicInterpolation.Interpolate1D(13);
    lagrangeInterpolation.Interpolate1D(13);

    std::pair<float, float> linearReg = Enumerator::linearRegression(x, y);
    std::cout << Enumerator::rmse(x, y) << std::endl;
    std::cout << linearReg.first << " " << linearReg.second << std::endl;

    LinearRegressor linearRegressor;
    linearRegressor.fit(x, y);

    std::pair<float, float> coeffs = linearRegressor.getCoefficients();
    std::cout << coeffs.first << " " << coeffs.second << std::endl;

    std::vector<float> predictedValues = linearRegressor.predict(x);
    for(float value : predictedValues)
    {
        std::cout << value << std::endl;
    }

    return 0;
}