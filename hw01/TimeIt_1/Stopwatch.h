#pragma once

#ifndef STOPWATCH_H
#define STOPWATCH_H


#include <iostream>
#include <chrono>


using namespace std::chrono;


class Stopwatch
{
public:
	Stopwatch();

	void start();

	void stop();

	void reportSec();

	void reportMilli();


private:
	time_point<system_clock> start_;

	time_point<system_clock> end_;

};


#endif