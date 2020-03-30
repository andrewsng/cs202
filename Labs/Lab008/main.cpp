/*
	main.cpp
	Andrew Ng
	Mar 29, 2020
	lab 8 for cs202
*/


#include <iostream>
#include "Complex.h"


int main()
{
	std::cout << "Complex + Complex\n";
	std::cout << Complex(2, 3) + Complex(4, 5) << "\n";

	std::cout << "double + Complex\n";
	std::cout << 1.0 + Complex(2, 3) << "\n";

	std::cout << "Complex + double\n";
	std::cout << Complex(4, 5) + 1 << "\n";

	std::cout << "complex1\n";
	Complex complex1(6, 7);
	std::cout << complex1 << "\n";

	std::cout << "complex2\n";
	Complex complex2(8, 9);
	std::cout << complex2 << "\n";

	std::cout << "complex1 += complex2\n";
	complex1 += complex2;
	std::cout << complex1 << "\n";
}