//
// Created by Busiu on 17.10.2018.
//

#ifndef MOWNIT2_LAGRANGEINTERPOLATION_HPP
#define MOWNIT2_LAGRANGEINTERPOLATION_HPP

#include "IInterpolation.hpp"
#include "Templates.cpp"

class LagrangeInterpolation : public IInterpolation
{
private:
    const PointsList1D &pointsList1D;

public:
    explicit LagrangeInterpolation(const PointsList1D& points);

    void Interpolate1D(int pointsToInterpolate) override;
    void Interpolate2D(int pointsToInterpolate) override;

private:
    float calculateLagrange(float x);

};


#endif //MOWNIT2_LAGRANGEINTERPOLATION_HPP
