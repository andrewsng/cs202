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
    TspSolver random1;
    random1.SolveRandomly("dsj1000.tsp", 1);
	random1.outputSVG("dsj1000Rand.svg", 1700, 1000);

	TspSolver random2;
	random2.SolveRandomly("u1432.tsp", 1);
	random2.outputSVG("u1432Rand.svg", 1700, 1000);

	TspSolver random3;
	random3.SolveRandomly("fnl4461.tsp", 1);
	random3.outputSVG("fnl4451Rand.svg", 1700, 1000);

	TspSolver random4;
	random4.SolveRandomly("rl11849.tsp", 1);
	random4.outputSVG("rl11849Rand.svg", 1700, 1000);

	TspSolver random5;
	random5.SolveRandomly("usa13509.tsp", 1);
	random5.outputSVG("usa13509Rand.svg", 1700, 1000);
}