//
// Created by Busiu on 20.10.2018.
//

#ifndef MOWNIT2_LINEARREGRESSOR_HPP
#define MOWNIT2_LINEARREGRESSOR_HPP

#include "Templates.cpp"

class LinearRegressor
{
private:
    std::pair<float, float> coefficients;

public:
    LinearRegressor() = default;

    void fit(const std::vector<float>& x, const std::vector<float>& y);
    std::vector<float> predict(const std::vector<float>& x);

    std::pair<float, float> getCoefficients();

};

#endif //MOWNIT2_LINEARREGRESSOR_HPP
