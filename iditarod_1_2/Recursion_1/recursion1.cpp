#include <iostream>


unsigned long long fib(int n)
{
	if (n < 2) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}


unsigned long long fib_loop(int n)
{
	if (n < 2) {
		return n;
	}
	unsigned long long result = 0;
	unsigned long long prev2 = 0;
	unsigned long long prev1 = 1;
	for (int i = 1; i < n; i++) {
		result = (prev1 + prev2);
		prev2 = prev1;
		prev1 = result;
	}
	return result;
}


unsigned long long factorial(int n)
{
	if (n == 0) {
		return 1;
	}
	return n * factorial(n - 1);
}


int main()
{
	//std::cout << fib(50) << "\n";
	//std::cout << fib_loop(50) << "\n";
	std::cout << factorial(20) << "\n";
}