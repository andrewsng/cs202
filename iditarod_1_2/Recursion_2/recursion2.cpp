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
}