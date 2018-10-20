//
// Created by Busiu on 17.10.2018.
//

#ifndef MOWNIT2_LAB2_TEMPLATES_CPP
#define MOWNIT2_LAB2_TEMPLATES_CPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <cmath>

typedef std::vector<float> PointsList1D;
typedef std::vector<std::array<float, 2>> PointsList2D;

/// <summary>
/// Template function used for clamping specified datasets
/// </summary>
template <typename T>
T GetIndexClamped(const std::vector<T> points, int index)
{
    if (index < 0)
        return points[0];
    else if (index >= int(points.size()))
        return points.back();
    else
        return points[index];
}

#endif //MOWNIT2_LAB2_TEMPLATES_CPP
