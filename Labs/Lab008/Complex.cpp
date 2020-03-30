#include "Complex.h"


Complex::Complex(double real, double imag)
	: real_(real), imag_(imag)
{}


Complex Complex::operator+(const Complex other)
{
	return Complex(real_ + other.getReal(),
		imag_ + other.getImag());
}


Complex& Complex::operator+=(const Complex other)
{
	*this = *this + other;
	return *this;
}


std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
	os << complex.getReal();
	os << " + i ";
	os << complex.getImag();
	return os;
}


Complex operator+(double lhs, const Complex rhs)
{
	return Complex(lhs + rhs.getReal(), rhs.getImag());
}