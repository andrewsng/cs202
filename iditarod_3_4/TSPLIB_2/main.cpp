/*
    main.cpp
    Andrew Ng
    Apr 14, 2020
    main for TSPLIB part 2
*/


#include <iostream>
#include "CityList.h"
#include "TspSolver.h"


int main()
{
    TspSolver random;
    random.SolveRandomly("usa13509.tsp", 100);
    // usa13509 best: 2.11143e+09

    TspSolver greedy;
    greedy.SolveGreedy("usa13509.tsp");
}