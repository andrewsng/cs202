#include <iostream>
#include <vector>
#include <algorithm>
#include "Stopwatch.h"


using std::cout;
using std::endl;
using std::vector;


int main()
{
	Stopwatch newTime;
	newTime.stop();
	newTime.reportSec();
	newTime.reportMilli();
}