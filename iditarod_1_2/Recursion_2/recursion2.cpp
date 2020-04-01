#include <iostream>


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
		for (int n = 0; n < 100; n++) {
			if (m == 3 && n == 12) {
				break;
			}
			if (m == 4 && n == 1) {
				break;
			}
			std::cout << "A(" << m << ", " << n;
			std::cout << ") = " << ack(m, n) << "\n";
		}
	}
}