//
// Created by Busiu on 17.10.2018.
//

#ifndef MOWNIT2_IINTERPOLATION_HPP
#define MOWNIT2_IINTERPOLATION_HPP

#include <iostream>
#include <vector>
#include <array>
#include <cmath>

/// <summary>
/// Defines structure for interpolation classes
/// </summary>
class IInterpolation
{
    // public construction and destruction methods
public:
    virtual ~IInterpolation() = default;

    // public interface methods
public:
    virtual void Interpolate1D(int pointsToInterpolate) =  0;
    virtual void Interpolate2D(int pointsToInterpolate) =  0;

};

#endif //MOWNIT2_IINTERPOLATION_HPP
