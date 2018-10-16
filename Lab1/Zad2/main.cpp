//
// Created by Busiu on 10.10.2018.
//

#include <iostream>

template <class T>
void calculateSequence(int length, T startElement)
{
    std::cout.precision(20);
    std::cout << startElement << std::endl;
    for(int i = 0; i < length; i++)
    {
        startElement = 2 * startElement + static_cast<T> (1.0);
        std::cout << startElement << std::endl;
    }
}

int main()
{
    calculateSequence(100, static_cast<float> (0.001));
    calculateSequence(100, static_cast<double> (0.001));

    return 0;
}
