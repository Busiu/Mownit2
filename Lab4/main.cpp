//
// Created by Busiu on 31.10.2018.
//

#include <iostream>
#include <pthread_time.h>

#include "DFT.hpp"
#include "FFT.hpp"

double getTimeInterval(struct timespec& timeStart, struct timespec& timeEnd)
{
    double timeElapsed = (timeEnd.tv_nsec - timeStart.tv_nsec) / 1000000.0;
    timeElapsed += (timeEnd.tv_sec - timeStart.tv_sec) * 1000.0;

    return timeElapsed;
}


int main()
{
    std::cout << "Lab 4" << std::endl;

    // Zadanie 1 -------------------------------------------------------------------------------------------------------

    std::vector<double> initDFTTest { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };

    DFT dftTest;
    dftTest.init(initDFTTest);
    dftTest.calculate();
    std::vector<std::complex<double>> dftResults = dftTest.getResults();
    size_t dftResultSize = dftResults.size();

    std::cout << "DFT: " << std::endl;
    for(size_t i = 0; i < dftResultSize; i++)
    {
        std::cout << "Sample nr " << i << ": " << dftResults[i] << std::endl;
    }
    std::cout << std::endl;

    // Zadanie 2 -------------------------------------------------------------------------------------------------------

    std::vector<double> initFFTTest { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };

    FFT fftTest;
    fftTest.init(initFFTTest);
    fftTest.calculate();
    std::valarray<std::complex<double>> fftResults = fftTest.getResults();
    size_t fftResultSize = fftResults.size();

    std::cout << "FFT: " << std::endl;
    for(size_t i = 0; i < fftResultSize; i++)
    {
        std::cout << "Sample nr " << i << ": " << fftResults[i] << std::endl;
    }
    std::cout << std::endl;

    // Zadanie 3 -------------------------------------------------------------------------------------------------------

    std::vector<std::vector<double>> datas;
    datas.resize(10);

    for(int i = 0; i < datas.size(); i++)
    {
        auto dataSize = static_cast<size_t> (std::pow(2, i + 4));
        datas[i].resize(dataSize);
        for(int j = 0; j < dataSize; j++)
        {
            datas[i][j] = j;
        }
    }

    for(int i = 0; i < datas.size(); i++)
    {
        struct timespec timeStart;
        struct timespec timeEnd;
        double timeInterval;

        std::cout << "Measurements for " << datas[i].size() << " samples:" << std::endl;

        std::cout << "\tDFT: ";
        DFT dft;
        dft.init(datas[i]);
        clock_gettime(CLOCK_MONOTONIC, &timeStart);
        dft.calculate();
        clock_gettime(CLOCK_MONOTONIC, &timeEnd);
        timeInterval = getTimeInterval(timeStart, timeEnd);
        std::cout << timeInterval << " ms" << std::endl;

        std::cout << "\tFFT: ";
        FFT fft;
        fft.init(datas[i]);
        clock_gettime(CLOCK_MONOTONIC, &timeStart);
        fft.calculate();
        clock_gettime(CLOCK_MONOTONIC, &timeEnd);
        timeInterval = getTimeInterval(timeStart, timeEnd);
        std::cout << timeInterval << " ms" << std::endl;
    }

    return 0;
}
