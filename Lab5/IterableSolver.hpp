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
    AGHMatrix<double> SORMethod(AGHMatrix<double>& A, AGHMatrix<double>& B, double relaxation, int K);

    void printJacobiIterations(AGHMatrix<double>& A, AGHMatrix<double>& B, int K);
    void printGaussSeidelIterations(AGHMatrix<double>& A, AGHMatrix<double>& B, int K);
    void printSORIterations(AGHMatrix<double>& A, AGHMatrix<double>& B, double relaxation, int K);

};


#endif //MOWNIT2_ITERABLESOLVER_HPP
