//
// Created by Busiu on 14.11.2018.
//

#ifndef MOWNIT2_ITERABLESOLVER_HPP
#define MOWNIT2_ITERABLESOLVER_HPP

#include <iostream>

#include "AGHMatrix.hpp"


class IterableSolver {
private:

public:
    explicit IterableSolver() = default;
    ~IterableSolver() = default;

    AGHMatrix<double> jacobiMethod(AGHMatrix<double>& A, AGHMatrix<double>& B, int K);
    AGHMatrix<double> gaussSeidelMethod(AGHMatrix<double>& A, AGHMatrix<double>& B, int K);

};


#endif //MOWNIT2_ITERABLESOLVER_HPP
