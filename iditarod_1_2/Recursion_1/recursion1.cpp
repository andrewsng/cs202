#include <iostream>


unsigned long long fib(int n)
{
	if (n < 2) {
		return n;
	}

	return fib(n - 1) + fib(n - 2);
}


int main()
{
	std::cout << fib(50) << "\n";
}