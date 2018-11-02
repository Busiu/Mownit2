//
// Created by Busiu on 31.10.2018.
//

#ifndef MOWNIT2_COMPLEX_HPP
#define MOWNIT2_COMPLEX_HPP

#include <cmath>
#include <iostream>
#include <utility>

template <class T> class Complex
{

public:
    T x;
    T y;

public:
    Complex(T x, T y);
    Complex();

    Complex operator+(const Complex& complex);
    Complex operator-(const Complex& complex);
    Complex operator*(const Complex& complex);
    Complex operator/(const Complex& complex);

    Complex operator*(const T& t);

    Complex operator+=(const Complex& complex);
    Complex operator-=(const Complex& complex);
    Complex operator*=(const Complex& complex);
    Complex operator/=(const Complex& complex);

    bool operator>(const Complex& complex) const;
    bool operator<(const Complex& complex) const;

    T getModule() const;

    template<class Type> friend std::ostream& operator << (std::ostream& os, const Complex<Type>& complex);
    template<class Type> friend std::istream& operator >> (std::istream& is, Complex<Type>& complex);

    Complex& operator++() = delete;
    const Complex operator++(int) = delete;

};

#endif //MOWNIT2_COMPLEX_HPP
