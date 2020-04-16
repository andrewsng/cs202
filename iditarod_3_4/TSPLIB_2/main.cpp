/*
    main.cpp
    Andrew Ng
    Apr 14, 2020
    main for TSPLIB part 2
*/


#include <iostream>
#include "CityList.h"
#include "TspSolver.h"
#include "Stopwatch.h"


int main()
{
	std::cout << "---SolveRandomly---\n";
    TspSolver random;
	Stopwatch randomSW;
    random.SolveRandomly("fnl4461.tsp", 10000);
	randomSW.stop();
	randomSW.reportSec();
	std::cout << "\n";
    // usa13509 best: 2.11143e+09

	std::cout << "---SolveGreedy (Nearest Neighbor)---\n";
    TspSolver greedy;
	Stopwatch greedySW;
    greedy.SolveGreedy("fnl4461.tsp");
	greedySW.stop();
	greedySW.reportSec();
	std::cout << "\n";

	std::cout << "---SolveMyWay (Nearest Insertion)---\n";
	TspSolver myWay;
	Stopwatch myWaySW;
	myWay.SolveMyWay("fnl4461.tsp");
	myWaySW.stop();
	myWaySW.reportSec();
	std::cout << "\n";
}