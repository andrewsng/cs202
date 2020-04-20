// Lab013.cpp
// Andrew Ng
// Apr 19, 2020
// Lab 13 main for cs202


#include <iostream>
#include <string>
#include "Wrapper.h"


int main(int argc, char** argv)
{
	Wrapper<int> w(2);
	Wrapper<std::string> s("Hello world!");

	std::cout << w << " " << s << std::endl;

	return 0;
}