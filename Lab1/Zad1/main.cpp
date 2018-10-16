#include <iostream>

int main()
{
    float float32 = static_cast<float>(1)/3;
    double float64 = static_cast<double>(1)/3;
    float floatCast = static_cast<float>(1)/3;

    std::cout.precision(15);
    std::cout << float32 << std::endl;
    std::cout << float64 << std::endl;
    std::cout << static_cast<double> (floatCast) << std::endl;

    return 0;
}