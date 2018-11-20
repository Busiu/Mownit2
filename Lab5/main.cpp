//
// Created by Busiu on 14.11.2018.
//

#include <iostream>

#include "AGHMatrix.hpp"
#include "IterableSolver.hpp"


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
    std::cout << "Lab 5" << std::endl;

    //  Inicjalizacja --------------------------------------------------------------------------------------------------

    IterableSolver solver;

    std::vector<std::vector<double>> A1 { { 2.0, 1.0 },
                                          { 5.0, 7.0 } };
    std::vector<std::vector<double>> B1 { { 11.0 },
                                          { 13.0 } };
    std::vector<std::vector<double>> A2 { { 16.0, 3.0 },
                                          { 7.0, -11.0 } };
    std::vector<std::vector<double>> B2 { { 11.0 },
                                          { 13.0 } };
    std::vector<std::vector<double>> A3 { { 2.0, -1.0, 1.0 },
                                          { 8.0, 2.0, -5.0 },
                                          { 4.0, 1.0, 1.0 } };
    std::vector<std::vector<double>> B3 { { -4.0 },
                                          { -10.0 },
                                          { 2.0 } };
    std::vector<std::vector<double>> A4 { { 4.0, -1.0, -0.2, 2.0 },
                                          { -1.0, 5.0, 0.0, -2.0 },
                                          { 0.2, 1.0, 10.0, -1.0 },
                                          { 0.0, -2.0, -1.0, 4.0 } };
    std::vector<std::vector<double>> B4 { { 30.0 },
                                          { 0.0 },
                                          { -10.0 },
                                          { 5.0 } };
    std::vector<std::vector<double>> A5 { { 10.0, -1.0, 2.0, 0.0 },
                                          { -1.0, 11.0, -1.0, 3.0 },
                                          { 2.0, -1.0, 10.0, -1.0 },
                                          { 0.0, 3.0, -1.0, 8.0 } };
    std::vector<std::vector<double>> B5 { { 6.0 },
                                          { 25.0 },
                                          { -11.0 },
                                          { 15.0 } };

    AGHMatrix<double> matrixA1(A1);
    AGHMatrix<double> matrixB1(B1);
    AGHMatrix<double> matrixA2(A2);
    AGHMatrix<double> matrixB2(B2);
    AGHMatrix<double> matrixA3(A3);
    AGHMatrix<double> matrixB3(B3);
    AGHMatrix<double> matrixA4(A4);
    AGHMatrix<double> matrixB4(B4);
    AGHMatrix<double> matrixA5(A5);
    AGHMatrix<double> matrixB5(B5);

    //  Zadanie 1 ------------------------------------------------------------------------------------------------------

    AGHMatrix<double> jacobiSolution1 = solver.jacobiMethod(matrixA1, matrixB1, 25);
    AGHMatrix<double> jacobiSolution2 = solver.jacobiMethod(matrixA2, matrixB2, 25);
    AGHMatrix<double> jacobiSolution3 = solver.jacobiMethod(matrixA3, matrixB3, 25);
    AGHMatrix<double> jacobiSolution4 = solver.jacobiMethod(matrixA4, matrixB4, 25);
    AGHMatrix<double> jacobiSolution5 = solver.jacobiMethod(matrixA5, matrixB5, 25);

    std::cout << "Metoda Jacobiego:" << std::endl;
    std::cout << jacobiSolution1;
    std::cout << jacobiSolution2;
    std::cout << jacobiSolution3;
    std::cout << jacobiSolution4;
    std::cout << jacobiSolution5;

    //  Zadanie 2 ------------------------------------------------------------------------------------------------------

    AGHMatrix<double> gaussSeidelSolution1 = solver.gaussSeidelMethod(matrixA1, matrixB1, 25);
    AGHMatrix<double> gaussSeidelSolution2 = solver.gaussSeidelMethod(matrixA2, matrixB2, 25);
    AGHMatrix<double> gaussSeidelSolution3 = solver.gaussSeidelMethod(matrixA3, matrixB3, 25);
    AGHMatrix<double> gaussSeidelSolution4 = solver.gaussSeidelMethod(matrixA4, matrixB4, 25);
    AGHMatrix<double> gaussSeidelSolution5 = solver.gaussSeidelMethod(matrixA5, matrixB5, 25);

    std::cout << "Metoda Gaussa-Seidela:" << std::endl;
    std::cout << gaussSeidelSolution1;
    std::cout << gaussSeidelSolution2;
    std::cout << gaussSeidelSolution3;
    std::cout << gaussSeidelSolution4;
    std::cout << gaussSeidelSolution5;

    //  Zadanie 3 ------------------------------------------------------------------------------------------------------

    AGHMatrix<double> SORSolution1 = solver.SORMethod(matrixA1, matrixB1, 1.2, 25);
    AGHMatrix<double> SORSolution2 = solver.SORMethod(matrixA2, matrixB2, 1.2, 25);
    AGHMatrix<double> SORSolution3 = solver.SORMethod(matrixA3, matrixB3, 1.2, 25);
    AGHMatrix<double> SORSolution4 = solver.SORMethod(matrixA4, matrixB4, 1.2, 25);
    AGHMatrix<double> SORSolution5 = solver.SORMethod(matrixA5, matrixB5, 1.2, 25);

    std::cout << "Metoda SOR-a:" << std::endl;
    std::cout << SORSolution1;
    std::cout << SORSolution2;
    std::cout << SORSolution3;
    std::cout << SORSolution4;
    std::cout << SORSolution5;

    //  Zadanie 5 ------------------------------------------------------------------------------------------------------

    std::cout << "Iteracje Jacobiego:" << std::endl;
    solver.printJacobiIterations(matrixA1, matrixB1, 25);
    solver.printJacobiIterations(matrixA2, matrixB2, 25);
    solver.printJacobiIterations(matrixA3, matrixB3, 25);
    solver.printJacobiIterations(matrixA4, matrixB4, 25);
    solver.printJacobiIterations(matrixA5, matrixB5, 25);
    std::cout << "------------------------" << std::endl;

    std::cout << "Iteracje Gaussa-Seidela:" << std::endl;
    solver.printGaussSeidelIterations(matrixA1, matrixB1, 25);
    solver.printGaussSeidelIterations(matrixA2, matrixB2, 25);
    solver.printGaussSeidelIterations(matrixA3, matrixB3, 25);
    solver.printGaussSeidelIterations(matrixA4, matrixB4, 25);
    solver.printGaussSeidelIterations(matrixA5, matrixB5, 25);
    std::cout << "------------------------" << std::endl;

    std::cout << "Iteracje SOR-a:" << std::endl;
    solver.printSORIterations(matrixA1, matrixB1, 1.2, 25);
    solver.printSORIterations(matrixA2, matrixB2, 1.2, 25);
    solver.printSORIterations(matrixA3, matrixB3, 1.2, 25);
    solver.printSORIterations(matrixA4, matrixB4, 1.2, 25);
    solver.printSORIterations(matrixA5, matrixB5, 1.2, 25);
    std::cout << "------------------------" << std::endl;

}
