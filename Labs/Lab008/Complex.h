#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
public:
	Complex()
	{}

	Complex(double real, double imag = 0);

	double getReal() const { return real_; }

	double getImag() const { return imag_; }

	Complex operator+(const Complex other);

	Complex& operator+=(const Complex other);

private:
	double real_{ 0.0 };
	double imag_{ 0.0 };
};

std::ostream& operator<<(std::ostream& os, const Complex& complex);

Complex operator+(double lhs, const Complex rhs);

#endif