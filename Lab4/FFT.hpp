//
// Created by Busiu on 03.11.2018.
//

#ifndef MOWNIT2_FFT_HPP
#define MOWNIT2_FFT_HPP

#include <complex>
#include <iostream>
#include <valarray>
#include <vector>

class FFT
{
private:
    std::vector<double> specimen;
    std::valarray<std::complex<double>> results;
    unsigned noSamples;

public:
    FFT() = default;
    ~FFT() = default;

    void init(std::vector<double>& specimen);
    void calculate();
    std::valarray<std::complex<double>> getResults();

private:
    void initResultValues();
    void fft(std::valarray<std::complex<double>>& array);

};


#endif //MOWNIT2_FFT_HPP
