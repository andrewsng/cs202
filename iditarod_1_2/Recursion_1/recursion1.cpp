/*
	recursion1.cpp
	Andrew Ng
	March 31, 2020
	fibonacci and factorial functions
	for Iditarod Challenge 1
*/


#include <iostream>
#include <map>
#include <iomanip>


unsigned long long fib(int n, 
	std::map<int, unsigned long long>& cache)
{
	if (cache.count(n) != 0) {
		return cache.at(n);
	}
	if (n < 2) {
		cache[n] = n;
		return n;
	}
	unsigned long long result = fib(n - 1, cache) + fib(n - 2, cache);
	cache[n] = result;
	return result;
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


unsigned long long factorial_loop(int n)
{
	unsigned long long result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}


int main()
{
	std::cout << "fib(93) using map to cache values: \n";
	std::map<int, unsigned long long> fibCache;
	std::cout << fib(93, fibCache) << "\n\n";

	std::cout << "Stored values in fibonacci cache: \n";
	std::cout << " n | fib(n)\n";
	for (auto it = fibCache.begin(); it != fibCache.end(); it++) {
		std::cout << std::setw(2) << it->first << " | " << it->second << "\n";
	}
	
	std::cout << "\nfib_loop(93): \n";
	std::cout << fib_loop(93) << "\n\n";

	std::cout << "factorial(20):\n";
	std::cout << factorial(20) << "\n\n";

	std::cout << "factorial_loop(20):\n";
	std::cout << factorial_loop(20) << "\n";
}