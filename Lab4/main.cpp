//
// Created by Busiu on 31.10.2018.
//

#include <iostream>
#include "DFT.hpp"

int main(void)
{
    std::cout << "Lab 4" << std::endl;

    std::vector<double> initDFTTest { 1.0, 2.0, 3.0 };

    DFT dftTest;
    dftTest.init(initDFTTest);
    dftTest.calculate();
    std::vector<Complex<double>> dftResults = dftTest.getResults();

    std::cout << dftResults[0].x << " " << dftResults[0].y << std::endl;
    std::cout << dftResults[1].x << " " << dftResults[1].y << std::endl;
    std::cout << dftResults[2].x << " " << dftResults[2].y << std::endl;

    return 0;
}
