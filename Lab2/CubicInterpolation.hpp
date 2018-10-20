//
// Created by Busiu on 17.10.2018.
//

#ifndef MOWNIT2_CUBICINTERPOLATION_HPP
#define MOWNIT2_CUBICINTERPOLATION_HPP

#include "IInterpolation.hpp"
#include "Templates.cpp"

/// <summary>
/// Defines Hermite Cubic Interpolation
/// </summary>
class CubicInterpolation : public IInterpolation
{
private:
    const PointsList2D &pointsList2D;
    const PointsList1D &pointsList1D;
    struct PolynomialCoeffs
    {
        float A, B, C, D;
    };

public:
    explicit CubicInterpolation(const PointsList2D &points2D, const PointsList1D &points1D);

    void Interpolate2D(int pointsToInterpolate) override;
    void Interpolate1D(int pointsToInterpolate) override;

private:
    float CubicHermite(PolynomialCoeffs coeffs, float t) const;

};

#endif //MOWNIT2_CUBICINTERPOLATION_HPP
