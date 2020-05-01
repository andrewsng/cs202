/*
	TspSolver.h
	Andrew Ng
	Apr 14, 2020
	header for TspSolver class
*/


#ifndef TSPSOLVER_H
#define TSPSOLVER_H


#include "CityList.h"
#include "CityPath.h"
#include <iostream>
#include <string>
#include <random>
#include <fstream>


class TspSolver
{
public:

    TspSolver()
    {}

    ~TspSolver()
    {}

    void SolveRandomly(const std::string& fileName, unsigned int limit);

    void SolveGreedy(const std::string& fileName);

	void SolveMyWay(const std::string& fileName);

	void outputSVG(const std::string& fileName,
		unsigned int width, unsigned int height);

	void outputPoints(unsigned int width, unsigned int height,
		unsigned int windowX, unsigned int windowY, std::vector<float>& points);

	void outputLines(unsigned int width, unsigned int height,
		unsigned int windowX, unsigned int windowY, std::vector<float>& lines);

private:

    CityList cities_;
    CityPath route_;

};

#endif