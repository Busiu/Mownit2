//
// Created by Busiu on 24.10.2018.
//

#ifndef MOWNIT2_AGHMATRIX_HPP
#define MOWNIT2_AGHMATRIX_HPP

#include <vector>
#include <iostream>
#include <cmath>

template <typename T> class AGHMatrix;

template <typename T> struct LUMatrixes
{
    AGHMatrix<T> L;
    AGHMatrix<T> U;
};
template <typename T> struct CholeskyMatrixes
{
    AGHMatrix<T> L;
    AGHMatrix<T> LTrans;
};
template <typename T> struct LDUMatrixes
{
    AGHMatrix<T> L;
    AGHMatrix<T> D;
    AGHMatrix<T> U;
};

template <typename T> class AGHMatrix
{
private:
    std::vector<std::vector<T>> matrix;
    unsigned rows;
    unsigned cols;

public:
    AGHMatrix(const std::vector<std::vector<T>>& matrix);
    AGHMatrix(unsigned _rows, unsigned _cols, const T& _initial);
    AGHMatrix(const AGHMatrix<T>& rhs);
    virtual ~AGHMatrix() = default;

    // Operator overloading, for "standard" mathematical matrix operations
    AGHMatrix<T>& operator=(const AGHMatrix<T>& rhs);

    // Matrix mathematical operations
    AGHMatrix<T> operator+(const AGHMatrix<T>& rhs);
    AGHMatrix<T> operator*(const AGHMatrix<T>& rhs);

    // Access the individual elements
    T& operator()(const unsigned& row, const unsigned& col);
    const T& operator()(const unsigned& row, const unsigned& col) const;

    bool isSymmetric() const;

    void transpose();

    // Factorization
    LUMatrixes<T> LUFactorization() const;
    LDUMatrixes<T> LDUFactorization() const;
    CholeskyMatrixes<T> choleskyFactorization() const;

    // Gauss elimination
    AGHMatrix<T> gaussElimination();

    // Access the row and column sizes
    unsigned getRows() const;
    unsigned getCols() const;
    long long getDeterminant() const;

private:
    //  Cholesky
    void choleskyEqualIndexes(AGHMatrix<T>& L, int& i) const;
    void choleskyInequalIndexes(AGHMatrix<T>& L, int& i, int& j) const;

    //  Switch rows
    void switchRows(int& first, int& second);
};

#endif //MOWNIT2_AGHMATRIX_HPP
