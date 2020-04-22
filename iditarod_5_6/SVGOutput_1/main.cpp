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
    /*TspSolver random1;
    random1.SolveRandomly("dsj1000.tsp", 1);
	random1.outputSVG("dsj1000Rand.svg", 1000, 1000);

	TspSolver random2;
	random2.SolveRandomly("u1432.tsp", 1);
	random2.outputSVG("u1432Rand.svg", 1000, 1000);

	TspSolver random3;
	random3.SolveRandomly("fnl4461.tsp", 1);
	random3.outputSVG("fnl4451Rand.svg", 1000, 1000);

	TspSolver random4;
	random4.SolveRandomly("rl11849.tsp", 1);
	random4.outputSVG("rl11849Rand.svg", 1000, 1000);

	TspSolver random5;
	random5.SolveRandomly("usa13509.tsp", 1);
	random5.outputSVG("usa13509Rand.svg", 1700, 1000);*/

	TspSolver greedy1;
	greedy1.SolveGreedy("dsj1000.tsp");
	greedy1.outputSVG("dsj1000Greedy.svg", 1000, 1000);

	TspSolver greedy2;
	greedy2.SolveGreedy("u1432.tsp");
	greedy2.outputSVG("u1432Greedy.svg", 1000, 1000);

	TspSolver greedy3;
	greedy3.SolveGreedy("fnl4461.tsp");
	greedy3.outputSVG("fnl4451Greedy.svg", 1000, 1000);

	TspSolver greedy4;
	greedy4.SolveGreedy("rl11849.tsp");
	greedy4.outputSVG("rl11849Greedy.svg", 1000, 1000);

	TspSolver greedy5;
	greedy5.SolveGreedy("usa13509.tsp");
	greedy5.outputSVG("usa13509Greedy.svg", 1700, 1000);

	/*TspSolver custom1;
	custom1.SolveMyWay("dsj1000.tsp");
	custom1.outputSVG("dsj1000Custom.svg", 1000, 1000);

	TspSolver custom2;
	custom2.SolveMyWay("u1432.tsp");
	custom2.outputSVG("u1432Custom.svg", 1000, 1000);

	TspSolver custom3;
	custom3.SolveMyWay("fnl4461.tsp");
	custom3.outputSVG("fnl4451Custom.svg", 1000, 1000);

	TspSolver custom4;
	custom4.SolveMyWay("rl11849.tsp");
	custom4.outputSVG("rl11849Custom.svg", 1000, 1000);

	TspSolver custom5;
	custom5.SolveMyWay("usa13509.tsp");
	custom5.outputSVG("usa13509Custom.svg", 1700, 1000);*/
}