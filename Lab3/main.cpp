//
// Created by Busiu on 24.10.2018.
//

#include <iostream>

#include "AGHMatrix.hpp"

template <typename Type>
std::ostream& operator<<(std::ostream& ostream, const AGHMatrix<Type>& matrix);

template<typename Type>
std::ostream& operator<<(std::ostream& ostream, const AGHMatrix<Type>& matrix)
{
    for (int i=0; i<matrix.getRows(); i++)
    {
        for (int j=0; j<matrix.getCols(); j++)
        {
            ostream << matrix(i,j) << ", ";
        }
        ostream << std::endl;
    }
    ostream << std::endl;
}


int main(void)
{
    std::cout << "Lab 3" << std::endl;

    // Zadanie 1 -------------------------------------------------------------------------------------------------------

    std::vector<std::vector<double>> init1 { { 1.0, 2.0, 3.0 },
                                             { 4.0, 5.0, 6.0 },
                                             { 7.0, 8.0, 9.0 } };
    std::vector<std::vector<double>> init2 { { 2.0, 4.0, 6.0 },
                                             { 8.0, 10.0, 12.0 },
                                             { 14.0, 16.0, 18.0 } };

    AGHMatrix<double> mat1(init1);
    AGHMatrix<double> mat2(init2);

    AGHMatrix<double> mat3 = mat1 + mat2;
    AGHMatrix<double> mat4 = mat1 * mat2;

    std::cout << mat3 << mat4;

    // Zadanie 2 -------------------------------------------------------------------------------------------------------

    std::vector<std::vector<double>> symmetric { { 10.0, 34.0, 3.0 },
                                                 { 34.0, 3.0, 4.0 },
                                                 { 3.0, 4.0, 5.0 } };
    std::vector<std::vector<double>> asymmetric { { 2.0, 4.0, 6.0 },
                                                  { 4.0, 8.0, 12.0 },
                                                  { 14.0, 16.0, 18.0 } };

    AGHMatrix<double> symMatrix(symmetric);
    AGHMatrix<double> asymMatrix(asymmetric);

    std::cout << symMatrix.isSymmetric() << " " << asymMatrix.isSymmetric() << std::endl << std::endl;
    std::cout << symMatrix.getDeterminant() << " " << asymMatrix.getDeterminant() << std::endl << std::endl;

    symMatrix.transpose();
    asymMatrix.transpose();

    std::cout << symMatrix << asymMatrix;

    // Zadanie 3 -------------------------------------------------------------------------------------------------------

    std::vector<std::vector<double>> init_LU {{ 5.0, 3.0, 2.0 },
                                              { 1.0, 2.0, 0.0 },
                                              { 3.0, 0.0, 4.0 }};

    AGHMatrix<double> matLU(init_LU);
    LUMatrixes<double> luMatrixes = matLU.LUFactorization();

    std::cout << luMatrixes.L << luMatrixes.U;

    // Zadanie 4 -------------------------------------------------------------------------------------------------------

    std::vector<std::vector<double>> init_cholesky {{ 4.0, 12.0, -16.0 },
                                                    { 12.0, 37.0, -43.0 },
                                                    { -16.0, -43.0, 98.0 }};

    AGHMatrix<double> matCholesky(init_cholesky);
    CholeskyMatrixes<double> choleskyMatrixes = matCholesky.choleskyFactorization();

    std::cout << choleskyMatrixes.L << choleskyMatrixes.LTrans;

    // Zadanie 5 -------------------------------------------------------------------------------------------------------

    std::vector<std::vector<double>> init_gauss {{ 1.0, 10.0, 9.0 },
                                                 { 3.0, 14.0, 5.0 },
                                                 { 6.0, 23.0, 3.0 }};

    AGHMatrix<double> matGauss(init_gauss);
    AGHMatrix<double> gaussMatrix = matGauss.gaussElimination();

    std::cout << gaussMatrix;

    return 0;
}