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
    LinearRegressor();
    void fit(std::vector<float> x, std::vector<float> y);
    std::vector<float> predict(std::vector<float> x);

};

#endif //MOWNIT2_LINEARREGRESSOR_HPP
