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

    void randomInit(const std::string& fileName);

	void randomStep();

    void greedyInit(const std::string& fileName);

	void greedyStep();

	void customInit(const std::string& fileName);

	void customStep();

	void outputPoints(unsigned int width, unsigned int height,
		unsigned int windowX, unsigned int windowY, std::vector<float>& points);

	void outputLines(unsigned int width, unsigned int height,
		unsigned int windowX, unsigned int windowY, std::vector<float>& lines);

private:

    CityList cities_;
    CityPath route_;
	bool solved_{ 0 };

	std::vector<CityNode> cities;
	CityList chosen;
	int start{ -1 };
	std::vector<int> unchosen;

};

#endif