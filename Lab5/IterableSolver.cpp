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
            int sum = 0;
            for(unsigned j = 0; j < size; j++)
            {
                sum += R(i, j) * X(j, 1);
            }
            X(i, 1) = (B(i, 1) - sum) / D(i, i);
        }
    }

    return X;
}

AGHMatrix<double> IterableSolver::gaussSeidelMethod(AGHMatrix<double>& A, AGHMatrix<double>& B, int K)
{

}
