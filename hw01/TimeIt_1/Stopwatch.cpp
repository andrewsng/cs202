#include "Stopwatch.h"


Stopwatch::Stopwatch()
{
	start_ = system_clock::now();
	end_ = start_;
}


void Stopwatch::start()
{
	start_ = system_clock::now();
	end_ = start_;
}


void Stopwatch::stop()
{
	end_ = system_clock::now();
}


void Stopwatch::reportSec()
{
	auto time = end_ - start_;
	std::cout << "Time in (s): "
		<< duration<double>(time).count() 
		<< std::endl;
}


void Stopwatch::reportMilli()
{
	auto time = end_ - start_;
	std::cout << "Time in (ms): "
		<< duration<double, std::milli>(time).count() 
		<< std::endl;
}