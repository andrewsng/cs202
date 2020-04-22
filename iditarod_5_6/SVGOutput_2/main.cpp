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
	/*TspSolver random;
	random.SolveRandomly("fnl4461.tsp", 1);
	//random3.outputSVG("fnl4451Rand.svg", 1000, 1000);*/

	TspSolver greedy;
	greedy.SolveGreedy("fnl4461.tsp");
	//greedy3.outputSVG("fnl4451Greedy.svg", 1000, 1000);

	/*TspSolver custom;
	custom.SolveMyWay("fnl4461.tsp");
	//custom3.outputSVG("fnl4451Custom.svg", 1000, 1000);*/
}