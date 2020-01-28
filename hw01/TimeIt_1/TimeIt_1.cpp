/*
TimeIt_1.cpp
Andrew Ng
Jan 26, 2020
main setup for measuring algorithms
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>
#include "Stopwatch.h"


using std::cout;
using std::endl;
using std::vector;


int main()
{
	for (int i = 1; i <= 9; ++i) {
		int size = pow(10, i);

		vector<int> orig(size);

		std::generate(orig.begin(), orig.end(),
			[size]() {
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<int> dist(1, size);
				return dist(gen);
			});

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(1, size);

		cout << "Vector Size: " << size << "\n";

		cout << "Algorithm: Sort\n";

		Stopwatch sortTime;
		std::sort(orig.begin(), orig.end());
		sortTime.stop();
		sortTime.reportSec();
		sortTime.reportMilli();


		auto searchIter = orig.begin() + dist(gen) - 1;

		cout << "Algorithm: Search\n";

		Stopwatch searchTime;
		std::search(orig.begin(), orig.end(), searchIter, searchIter + 1);
		searchTime.stop();
		searchTime.reportSec();
		searchTime.reportMilli();

		cout << "Algorithm: Binary Search\n";

		Stopwatch bSearchTime;
		std::binary_search(orig.begin(), orig.end(), *searchIter);
		bSearchTime.stop();
		bSearchTime.reportSec();
		bSearchTime.reportMilli();

		cout << "Algorithm: Accumulate\n";

		Stopwatch accumulateTime;
		unsigned long long int result = std::accumulate(orig.begin(), orig.end(), 0LL);
		accumulateTime.stop();
		accumulateTime.reportSec();
		accumulateTime.reportMilli();
		cout << "Sum Result: " << result << "\n";

		cout << "\n";
	}
}