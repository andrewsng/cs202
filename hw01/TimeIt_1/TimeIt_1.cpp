#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include "Stopwatch.h"


using std::cout;
using std::endl;
using std::vector;


int main()
{
	for (int i = 1; i < 5; ++i) {
		vector<int> v(pow(10, i));
		std::generate(v.begin(), v.end(),
			[n = pow(10, i)]() {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> dist(1, n);
			return dist(gen);
		});


		for (auto n : v) {
			cout << n << endl;
		}
		cout << endl;
	}
}