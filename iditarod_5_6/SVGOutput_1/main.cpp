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
    random.SolveRandomly("usa13509.tsp", 1);
	randomSW.stop();
	randomSW.reportSec();
	std::cout << "\n";
	random.outputSVG("usa13509Rand.svg", 1700, 1000);
    // usa13509 best: 2.11143e+09

	std::cout << "---SolveGreedy (Nearest Neighbor)---\n";
    TspSolver greedy;
	Stopwatch greedySW;
    greedy.SolveGreedy("usa13509.tsp");
	greedySW.stop();
	greedySW.reportSec();
	std::cout << "\n";
	greedy.outputSVG("usa13509Greedy.svg", 1700, 1000);

	/*std::cout << "---SolveMyWay (Nearest Insertion)---\n";
	TspSolver myWay;
	Stopwatch myWaySW;
	myWay.SolveMyWay("dsj1000.tsp");
	myWaySW.stop();
	myWaySW.reportSec();
	std::cout << "\n";*/
}