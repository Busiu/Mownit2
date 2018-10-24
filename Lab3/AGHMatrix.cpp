//
// Created by Busiu on 24.10.2018.
//

#include "AGHMatrix.hpp"

template<typename T>
AGHMatrix<T> AGHMatrix<T>::operator+(const AGHMatrix<T>& rhs)
{
    for(int x = 0; x < this->getRows(); x++)
    {
        for(int y = 0; y < this->getCols(); y++)
        {
            this->matrix.[x][y] += rhs.matrix[x][y];
        }
    }

    return *this;
}

template<typename T>
AGHMatrix<T> AGHMatrix<T>::operator*(const AGHMatrix<T>& rhs)
{
    AGHMatrix<T> result(this->getRows(), this->getCols(), 0);
    T sum = 0;

    for(int x = 0; x < this->getRows(); x++)
    {
        for(int y = 0; y < this[x]->getCols(); y++)
        {
            for(int z = 0; z < this->getRows(); z++)
            {
                sum += this->matrix.[x][z] * rhs.matrix[z][y];
            }
            result.matrix[x][y] = sum;
        }
    }

    return result;
}

template<typename T>
bool AGHMatrix<T>::isSymmetric() const
{
    bool result = true;

    for(int x = 0; x < this->getRows(); x++)
    {
        for(int y = 0; y < this->getCols(); y++)
        {
            if(this->matrix.[x][y] != this->matrix[y][x])
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
        for(int y = 0; y < this->getCols() - x; y++)
        {
            this->matrix[x][y] = this->matrix[y][x];
        }
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
        result = this->matrix[0][0];

        return result;
    }
    else
    {
        ///BIEREMY X = 0
        for(int y = 0; y < this->getCols(); y++)
        {
            AGHMatrix<T> tmp(getRows() - 1, getCols() - 1, 0);
            for(int x_tmp = 0; x_tmp < tmp.getRows(); x_tmp++)
            {
                for(int y_tmp = 0; y_tmp < tmp.getCols(); y_tmp++)
                {
                    tmp.matrix[x_tmp][y_tmp] = this->matrix[x_tmp + 1][y_tmp + 1];
                }
            }

            result += (pow(-1, 0 + y) * (tmp.getDeterminant()));
        }
    }

    return result;
}

//TODO: Obsluga wyjatkow

