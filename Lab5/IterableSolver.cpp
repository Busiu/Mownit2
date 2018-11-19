//
// Created by Busiu on 14.11.2018.
//

#include "IterableSolver.hpp"

AGHMatrix<double> IterableSolver::jacobiMethod(AGHMatrix<double>& A, AGHMatrix<double>& B, int K)
{
    AGHMatrix<double> X(A.getRows(), 1, 1);
    unsigned size = A.getRows();

    LDUMatrixes<double> LDU = A.LDUFactorization();
    AGHMatrix<double> D = LDU.D;
    AGHMatrix<double> R = LDU.L + LDU.U;

    for(int k = 0; k < K; k++)
    {
        for(unsigned i = 0; i < size; i++)
        {
            double sum = 0;
            for(unsigned j = 0; j < size; j++)
            {
                sum += R(i, j) * X(j, 0);
            }
            X(i, 0) = (B(i, 0) - sum) / D(i, i);
        }
    }

    return X;
}

AGHMatrix<double> IterableSolver::gaussSeidelMethod(AGHMatrix<double>& A, AGHMatrix<double>& B, int K)
{
    AGHMatrix<double> X(A.getRows(), 1, 1);
    unsigned size = A.getRows();

    LDUMatrixes<double> LDU = A.LDUFactorization();
    AGHMatrix<double> L = LDU.L;
    AGHMatrix<double> D = LDU.D;
    AGHMatrix<double> U = LDU.U;

    for(int k = 0; k < K; k++)
    {
        for(unsigned i = 0; i < size; i++)
        {
            double sumLStar = 0;
            double sumU = 0;
            for(unsigned j = 0; j < size; j++)
            {
                sumLStar += L(i, j) * X(j, 0);
                sumU += U(i, j) * X(j, 0);
            }
            X(i, 0) = (B(i, 0) - sumLStar - sumU) / D(i, i);
        }
    }

    return X;
}

AGHMatrix<double> IterableSolver::SORMethod(AGHMatrix<double>& A, AGHMatrix<double>& B, double relaxation, int K)
{
    AGHMatrix<double> X(A.getRows(), 1, 1);
    unsigned size = A.getRows();

    LDUMatrixes<double> LDU = A.LDUFactorization();
    AGHMatrix<double> L = LDU.L;
    AGHMatrix<double> D = LDU.D;
    AGHMatrix<double> U = LDU.U;

    for(int k = 0; k < K; k++)
    {
        for(unsigned i = 0; i < size; i++)
        {
            double sumLStar = 0;
            double sumU = 0;
            for(unsigned j = 0; j < size; j++)
            {
                sumLStar += L(i, j) * X(j, 0);
                sumU += U(i, j) * X(j, 0);
            }
            X(i, 0) = ((1 - relaxation) * X(i, 0)) + ((relaxation / D(i, i)) * (B(i, 0) - sumLStar - sumU));
        }
    }

    return X;
}

