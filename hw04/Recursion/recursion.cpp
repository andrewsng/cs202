/*
recursion.cpp
Andrew Ng
Mar 8, 2020
Recursive functions for hw04
*/


#include <iostream>
#include "Stopwatch.h"


unsigned long long fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}


unsigned long long fib_loop(int n)
{
	unsigned long long prev2 = 0;
	unsigned long long prev1 = 1;
	unsigned long long result = prev1 + prev2;
	for (int i = 1; i < n; ++i) {
		result = prev1 + prev2;
		prev2 = prev1;
		prev1 = result;
	}
	return result;
}


unsigned long long fact(int n)
{
	if (n == 0) {
		return 1;
	}
	return n * fact(n - 1);
}


unsigned long long fact_loop(int n) {
	unsigned long long result = 1;
	for (int i = 1; i <= n; ++i) {
		result *= i;
	}
	return result;
}


unsigned long long ack(unsigned long long m, unsigned long long n)
{
	if (m == 0) {
		return n + 1;
	}
	else if (m > 0 && n == 0) {
		return ack(m - 1, 1);
	}
	else if (m > 0 && n > 0) {
		return ack(m - 1, ack(m, n - 1));
	}
}


int main()
{
	std::cout << "--------RECURSION!--------\n\n";
	std::cout << "fib[50] recursive\n";
	Stopwatch fibTimeR;
	std::cout << fib(50) << "\n";
	fibTimeR.stop();
	fibTimeR.reportSec();
	fibTimeR.reportMilli();

	std::cout << "\nfib[50] non-recursive\n";
	Stopwatch fibTimeNR;
	std::cout << fib_loop(50) << "\n";
	fibTimeNR.stop();
	fibTimeNR.reportSec();
	fibTimeNR.reportMilli();

	std::cout << "\n20! recursive\n";
	Stopwatch factTimeR;
	std::cout << fact(20) << "\n";
	factTimeR.stop();
	factTimeR.reportSec();
	factTimeR.reportMilli();

	std::cout << "\n20! non-recursive\n";
	Stopwatch factTimeNR;
	std::cout << fact(20) << "\n";
	factTimeNR.stop();
	factTimeNR.reportSec();
	factTimeNR.reportMilli();

	std::cout << "\nAckermann's(3, 11)\n";
	Stopwatch ackTime;
	std::cout << ack(3, 11) << "\n";
	ackTime.stop();
	ackTime.reportSec();
	ackTime.reportMilli();
}