/*
	recursion2.cpp
	Andrew Ng
	March 31, 2020
	Ackermann's recursive function
	for Iditarod Challenge 2
*/


#include <iostream>
#include "Stopwatch.h"


int ack(int m, int n)
{
	if (m == 0) {
		return n + 1;
	}
	if (m > 0 && n == 0) {
		return ack(m - 1, 1);
	}
	if (m > 0 && n > 0) {
		return ack(m - 1, ack(m, n - 1));
	}
}


int main()
{
	// hard-coded breakpoints for complete run
	for (int m = 0; m < 5; m++) {
		for (int n = 0; n < 12; n++) {
			if (m == 4 && n == 1) {
				break;
			}

			int result;
			Stopwatch time;
			result = ack(m, n);
			time.stop();

			std::cout << "A(" << m << ", " << n;
			std::cout << ") = " << result << "\n";
			time.reportMilli();
		}
	}

	// infinite while loop to find max value
	/*int m = 4;
	int n = 0;
	while (true) {
		int result;
		Stopwatch time;
		result = ack(m, n);
		time.stop();

		std::cout << "A(" << m << ", " << n;
		std::cout << ") = " << result << "\n";
		time.reportMilli();

		n++;
	}*/
}