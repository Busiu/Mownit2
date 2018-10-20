//
// Created by Busiu on 20.10.2018.
//

#ifndef MOWNIT2_ENUMERATOR_HPP
#define MOWNIT2_ENUMERATOR_HPP

#include <iostream>
#include <vector>

class Enumerator {
private:

public:
    static float rmse(std::vector<float> x, std::vector<float> y);
    static std::pair<float,float> linearRegression (std::vector<float> x, std::vector<float> y);

};


#endif //MOWNIT2_ENUMERATOR_HPP
