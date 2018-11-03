//
// Created by Busiu on 31.10.2018.
//

#include "DFT.hpp"

void DFT::init(std::vector<double>& specimen)
{
    this->specimen = specimen;
    noSamples = static_cast<unsigned> (specimen.size());
    this->results.resize(noSamples);
}

void DFT::calculate()
{
    for(int k = 0; k < noSamples; k++)
    {
        std::complex<double> sum(0, 0);
        for(int n = 0; n < noSamples; n++)
        {
            sum += (std::polar(1.0, (-2 * M_PI * k * n) / noSamples) * specimen[n]);
        }
        results[k] = sum;
    }
}

std::vector<std::complex<double>> DFT::getResults()
{
    return results;
}



