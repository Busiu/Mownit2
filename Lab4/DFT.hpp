//
// Created by Busiu on 31.10.2018.
//

#ifndef MOWNIT2_DFT_HPP
#define MOWNIT2_DFT_HPP

#include <iostream>
#include <vector>

#include "Complex.hpp"

class DFT
{
private:
    std::vector<double> specimen;
    std::vector<Complex<double>> results;
    unsigned noSamples;

public:
    DFT() = default;
    ~DFT() = default;

    void init(std::vector<double>& specimen);
    void calculate();
    std::vector<Complex<double>> getResults();

};


#endif //MOWNIT2_DFT_HPP
