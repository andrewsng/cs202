/*
    main.cpp
    Andrew Ng
    Apr 22, 2020
    main for SVG Output part 2
*/


#include <iostream>
#include "CityList.h"
#include "TspSolver.h"
#include "Stopwatch.h"


int main()
{
	TspSolver random;
	random.SolveRandomly("fnl4461.tsp", 1);

	TspSolver greedy;
	greedy.SolveGreedy("fnl4461.tsp");

	TspSolver custom;
	custom.SolveMyWay("fnl4461.tsp");
}