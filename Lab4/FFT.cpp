//
// Created by Busiu on 03.11.2018.
//

#include "FFT.hpp"

void FFT::init(std::vector<double>& specimen)
{
    this->specimen = specimen;
    noSamples = static_cast<unsigned> (specimen.size());
    this->results.resize(noSamples);
}

void FFT::calculate()
{
    initResultValues();
    fft(results);
}

void FFT::initResultValues()
{
    const size_t N = specimen.size();
    for(size_t i = 0; i < N; i++)
    {
        results[i] = std::complex<double>(specimen[i], 0);
    }
}
void FFT::fft(std::valarray<std::complex<double>>& array)
{
    const size_t N = array.size();
    // To jest w zasadzie DFT z poprzedniego zadania
    if (N <= 1)
    {
        return;
    }

    // divide
    std::valarray<std::complex<double>> even = array[std::slice(0, N/2, 2)];
    std::valarray<std::complex<double>>  odd = array[std::slice(1, N/2, 2)];

    // conquer
    fft(even);
    fft(odd);

    // combine
    for (size_t k = 0; k < N/2; k++)
    {
        std::complex<double> t = std::polar(1.0, -2 * M_PI * k / N) * odd[k];
        array[k    ] = even[k] + t;
        array[k+N/2] = even[k] - t;
    }
}

std::valarray<std::complex<double>> FFT::getResults()
{
    return results;
}

std::valarray<double> FFT::getSpectrum()
{
    std::valarray<double> spectrum;
    spectrum.resize(results.size());

    for(int i = 0; i < spectrum.size(); i++)
    {
        spectrum[i] = abs(results[i]);
    }

    return spectrum;
}

