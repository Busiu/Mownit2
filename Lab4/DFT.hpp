//
// Created by Busiu on 31.10.2018.
//

#ifndef MOWNIT2_DFT_HPP
#define MOWNIT2_DFT_HPP

#include <complex>
#include <iostream>
#include <vector>

class DFT
{
private:
    std::vector<double> specimen;
    std::vector<std::complex<double>> results;
    unsigned noSamples;

public:
    DFT() = default;
    ~DFT() = default;

    void init(std::vector<double>& specimen);
    void calculate();
    std::vector<std::complex<double>> getResults();

};


#endif //MOWNIT2_DFT_HPP
