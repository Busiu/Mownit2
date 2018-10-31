//
// Created by Busiu on 24.10.2018.
//

#include "AGHMatrix.hpp"

// Parameter Constructor
template<typename T>
AGHMatrix<T>::AGHMatrix(const std::vector<std::vector<T>>& mat)
{
    matrix.resize(mat.size());
    for (unsigned i = 0; i < mat.size(); i++)
    {
        matrix[i].resize(mat[i].size());
        for(unsigned j = 0; j < mat[i].size(); j++)
        {
            matrix[i][j] = mat[i][j];
        }
    }
    rows = matrix.size();
    cols = matrix[1].size();
}

// Parameter Constructor
template<typename T>
AGHMatrix<T>::AGHMatrix(unsigned _rows, unsigned _cols, const T& _initial)
{
    matrix.resize(_rows);
    for (unsigned i=0; i<matrix.size(); i++)
    {
        matrix[i].resize(_cols, _initial);
    }
    rows = _rows;
    cols = _cols;
}

// Copy Constructor
template<typename T>
AGHMatrix<T>::AGHMatrix(const AGHMatrix<T>& rhs)
{
    matrix = rhs.matrix;
    rows = rhs.getRows();
    cols = rhs.getCols();
}

// Assignment Operator
template<typename T>
AGHMatrix<T>& AGHMatrix<T>::operator=(const AGHMatrix<T>& rhs)
{
    if (&rhs == this)
        return *this;

    unsigned new_rows = rhs.getRows();
    unsigned new_cols = rhs.getCols();

    matrix.resize(new_rows);
    for (unsigned i=0; i<matrix.size(); i++)
    {
        matrix[i].resize(new_cols);
    }

    for (unsigned i=0; i<new_rows; i++)
    {
        for (unsigned j=0; j<new_cols; j++)
        {
            matrix[i][j] = rhs(i, j);
        }
    }
    rows = new_rows;
    cols = new_cols;

    return *this;
}

template<typename T>
AGHMatrix<T> AGHMatrix<T>::operator+(const AGHMatrix<T>& rhs)
{
    AGHMatrix<T> result(this->getRows(), this->getCols(), 0);

    for(int x = 0; x < this->getRows(); x++)
    {
        for(int y = 0; y < this->getCols(); y++)
        {
            result(x, y) = (*this)(x, y) + rhs(x, y);
        }
    }

    return result;
}

template<typename T>
AGHMatrix<T> AGHMatrix<T>::operator*(const AGHMatrix<T>& rhs)
{
    AGHMatrix<T> result(this->getRows(), this->getCols(), 0);
    T sum = 0;

    for(int x = 0; x < this->getRows(); x++)
    {
        for(int y = 0; y < this->getCols(); y++)
        {
            for(int z = 0; z < this->getRows(); z++)
            {
                sum += (*this)(x, z) * rhs(z, y);
            }
            result(x, y) = sum;
        }
    }

    return result;
}

// Access the individual elements
template<typename T>
T& AGHMatrix<T>::operator()(const unsigned& row, const unsigned& col)
{
    return this->matrix[row][col];
}

// Access the individual elements (const)
template<typename T>
const T& AGHMatrix<T>::operator()(const unsigned& row, const unsigned& col) const
{
    return this->matrix[row][col];
}

template<typename T>
bool AGHMatrix<T>::isSymmetric() const
{
    bool result = true;

    for(int x = 0; x < this->getRows(); x++)
    {
        for(int y = 0; y < this->getCols(); y++)
        {
            if((*this)(x, y) != (*this)(y, x))
            {
                result = false;
            }
        }
    }

    return result;
}

template<typename T>
void AGHMatrix<T>::transpose()
{
    for(int x = 1; x < this->getRows(); x++)
    {
        for(int y = 0; y < x; y++)
        {
            std::swap((*this)(x, y), (*this)(y, x));
        }
    }
}

template<typename T>
LUMatrixes<T> AGHMatrix<T>::LUFactorization() const
{
    AGHMatrix<T> L(this->getRows(), this->getCols(), 0);
    AGHMatrix<T> U(this->getRows(), this->getCols(), 0);

    unsigned size = this->getRows();

    // Set diagonal of L
    for(int i = 0; i < size; i++)
    {
        L(i, i) = 1;
    }

    // Actual calculation
    for(int i = 0; i < size; i++)
    {
        // U row
        for(int j = i; j < size; j++)
        {
            T sum = 0;
            for(int k = 0; k <= i - 1; k++)
            {
                sum += (L(i, k) * U(k, j));
            }
            U(i, j) = ((*this)(i, j) - sum);
        }
        // L column
        for(int j = i + 1; j < size; j++)
        {
            T sum = 0;
            for(int k = 0; k <= i - 1; k++)
            {
                sum += (L(j, k) * U(k, i));
            }
            L(j, i) = ((*this)(j, i) - sum) / U(i, i);
        }
    }

    return LUMatrixes<T>{L, U};
}


template<typename T>
CholeskyMatrixes<T> AGHMatrix<T>::choleskyFactorization() const
{
    AGHMatrix<T> L(this->getRows(), this->getCols(), 0);

    unsigned size = this->getRows();

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i == j)
            {
                choleskyEqualIndexes(L, i);
            }
            else
            {
                choleskyInequalIndexes(L, i, j);
            }
        }
    }

    AGHMatrix<T> LTrans = L;
    LTrans.transpose();

    return CholeskyMatrixes<T>{L, LTrans};
}

template<typename T>
void AGHMatrix<T>::choleskyEqualIndexes(AGHMatrix<T>& L, int& i) const
{
    T sum = 0;
    for(int k = 0; k <= i - 1; k++)
    {
        sum += std::pow(L(i, k), 2);
    }

    L(i, i) = sqrt((*this)(i, i) - sum);
}
template<typename T>
void AGHMatrix<T>::choleskyInequalIndexes(AGHMatrix<T>& L, int& i, int& j) const
{
    T sum = 0;
    for(int k = 0; k <= j - 1; k++)
    {
        sum += (L(i, k) * L(j, k));
    }

    L(i, j) = ((*this)(i, j) - sum) / L(j, j);
}

template<typename T>
AGHMatrix<T> AGHMatrix<T>::gaussElimination()
{
    AGHMatrix<T> result = *this;
    int size = getRows();
    int i = 0;
    int j = 0;

    while(j < size)
    {
        bool isNonZeroNumber = false;

        // Jezeli nasz nastepny odejmujacy rzad zaczyna sie od 0 - zamieniamy go z jakims innym, ktory tej wady nie ma
        while(!isNonZeroNumber)
        {
            if (result(i, j) == 0)
            {
                for (int k = i + 1; i < size; k++)
                {
                    if (result(k, j) != 0)
                    {
                        isNonZeroNumber = true;
                        result.switchRows(i, k);
                        break;
                    }
                }

                if (!isNonZeroNumber)
                {
                    j++;
                }
            }
            else
            {
                isNonZeroNumber = true;
            }
        }

        // Faktyczne odejmowanie
        double a = result(i, j);
        for(int k = i + 1; k < size; k++)
        {
            double factor = result(k, j) / a;
            for(int l = j; l < size; l++)
            {
                result(k, l) -= (factor * result(i, l));
            }
        }

        i++;
        j++;
    }

    return result;
}

template <typename T>
void AGHMatrix<T>::switchRows(int& first, int& second)
{
    int size = getRows();
    for(int x = 0; x < size; x++)
    {
        std::swap((*this)(x, first), (*this)(x, second));
    }
}



template<typename T>
unsigned AGHMatrix<T>::getRows() const
{
    return rows;
}
template<typename T>
unsigned AGHMatrix<T>::getCols() const
{
    return cols;
}
template<typename T>
long long AGHMatrix<T>::getDeterminant() const
{

    long long result = 0;
    if(rows == 1)
    {
        result = (*this)(0, 0);

        return result;
    }
    else
    {
        ///BIEREMY Y = 0
        for(int x = 0; x < this->getCols(); x++)
        {
            AGHMatrix<T> tmp(getRows() - 1, getCols() - 1, 0);
            for(int x_tmp = 0; x_tmp < tmp.getRows(); x_tmp++)
            {
                for(int y_tmp = 0; y_tmp < tmp.getCols(); y_tmp++)
                {
                    if(x > x_tmp)
                    {
                        tmp(x_tmp, y_tmp) = (*this)(x_tmp, y_tmp + 1);
                    }
                    else
                    {
                        tmp(x_tmp, y_tmp) = (*this)(x_tmp + 1, y_tmp + 1);
                    }
                }
            }


            result += (pow(-1, x + 0) * (*this)(x, 0) * tmp.getDeterminant());
        }
    }

    return result;
}

template class AGHMatrix<double>;

//TODO: Obsluga wyjatkow

