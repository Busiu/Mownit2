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
        std::cout << "LOL k" << std::endl;
        Complex<double> sum(0, 0);
        for(int n = 0; n < noSamples; n++)
        {
            std::cout << "LOL n" << std::endl;
            sum += (sum * specimen[n]);
        }
        std::cout << "LOL end" << std::endl;
        results[k] = sum;
        std::cout << "LOL error" << std::endl;
    }
}

std::vector<Complex<double>> DFT::getResults()
{

    //TODO: Rzucenie wyjątku
    if(results.empty())
    {
        std::cout << "Results was not calculted!" << std::endl;

        std::vector<Complex<double>> empty;
        return empty;
    }
    else
    {
        return results;
    }
}



