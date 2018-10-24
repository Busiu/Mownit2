//
// Created by Busiu on 24.10.2018.
//

#ifndef MOWNIT2_AGHMATRIX_HPP
#define MOWNIT2_AGHMATRIX_HPP

#include <vector>
#include <iostream>
#include <cmath>

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

    // Printing matrix
    friend std::ostream& operator<<(std::ostream& ostream, const AGHMatrix<T>& matrix);

    bool isSymmetric() const;

    void transpose();

    // Factorization
    void LUFactorization();

    // Access the row and column sizes
    unsigned getRows() const;
    unsigned getCols() const;
    long long getDeterminant() const;
};


#endif //MOWNIT2_AGHMATRIX_HPP
