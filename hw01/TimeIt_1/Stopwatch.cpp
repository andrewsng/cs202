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

}


void Stopwatch::reportMilli()
{

}