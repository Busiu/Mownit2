//
// Created by Busiu on 17.10.2018.
//

#include "CubicInterpolation.hpp"

CubicInterpolation::CubicInterpolation(const PointsList2D &points2D, const PointsList1D &points1D) :
        pointsList2D(points2D),
        pointsList1D(points1D)
        {}

void CubicInterpolation::Interpolate2D(int pointsToInterpolate)
{
    std::vector<int> index(pointsToInterpolate);
    std::vector<float> t;
    std::vector<float> tx;

    int i = 0;
    int points_size = pointsList2D.size() - 1;
    std::generate(index.begin(), index.end(), [&i, &pointsToInterpolate, &points_size, &t, &tx]()
    {
        float percent = ((float)i) / (float(pointsToInterpolate - 1));
        tx.push_back((points_size)* percent);
        t.push_back(tx[i] - floor(tx[i]));
        return int(tx[i++]);
    });

    for (int i = 0; i < pointsToInterpolate; i++)
    {
        std::array<PolynomialCoeffs, 2> coeffs;
        std::array<float, 2> A = GetIndexClamped(pointsList2D, index[i] - 1);
        std::array<float, 2> B = GetIndexClamped(pointsList2D, index[i]);
        std::array<float, 2> C = GetIndexClamped(pointsList2D, index[i] + 1);
        std::array<float, 2> D = GetIndexClamped(pointsList2D, index[i] + 2);

        for (int j = 0; j < 2; j++)
        {
            coeffs[i].A = A[i];
            coeffs[i].B = B[i];
            coeffs[i].C = C[i];
            coeffs[i].D = D[i];
        }

        float x = CubicHermite(coeffs[0], t[i]);
        float y = CubicHermite(coeffs[1], t[i]);

        std::cout << "Value at " << tx[i] << " = " << x << "  " << y << std::endl;
    }
}
void CubicInterpolation::Interpolate1D(int pointsToInterpolate)
{
    std::vector<int> index(pointsToInterpolate);
    std::vector<float> t;
    std::vector<float> tx;

    int i = 0;
    int points_size = pointsList1D.size() - 1;
    std::generate(index.begin(), index.end(), [&i, &pointsToInterpolate, &points_size, &t, &tx]()
    {
        float percent = ((float)i) / (float(pointsToInterpolate - 1));
        tx.push_back((points_size)* percent);
        t.push_back(tx[i] - floor(tx[i]));
        return int(tx[i++]);
    });

    std::cout << "Cubic Interpolation 1D:" << std::endl;
    for (int i = 0; i < pointsToInterpolate; ++i)
    {
        PolynomialCoeffs coeffs;
        float A = GetIndexClamped(pointsList1D, index[i] - 1);
        float B = GetIndexClamped(pointsList1D, index[i]);
        float C = GetIndexClamped(pointsList1D, index[i] + 1);
        float D = GetIndexClamped(pointsList1D, index[i] + 2);

        coeffs.A = A;
        coeffs.B = B;
        coeffs.C = C;
        coeffs.D = D;

        float x = CubicHermite(coeffs, t[i]);

        std::cout << "Value at " << tx[i] << " = " << x << std::endl;
    }

    std::cout << std::endl;
}



float CubicInterpolation::CubicHermite(PolynomialCoeffs coeffs, float t) const
{
    float a = -coeffs.A / 2.0f + (3.0f*coeffs.B) / 2.0f - (3.0f*coeffs.C) / 2.0f + coeffs.D / 2.0f;
    float b = coeffs.A - (5.0f*coeffs.B) / 2.0f + 2.0f*coeffs.C - coeffs.D / 2.0f;
    float c = -coeffs.A / 2.0f + coeffs.C / 2.0f;
    float d = coeffs.B;

    return static_cast<float> (a * pow(t, 3) + b * pow(t, 2) + c * t + d);
}