/*
 main.cpp
 Andrew Ng
 Mar 24, 2020
 main for lab007 for cs202
*/


#include <iostream>
#include "Vec3.h"


int main()
{
	Vec3 myVec;
	std::cout << myVec << "\n";

	Vec3 myVec2;
	myVec2.setX(0.1234);
	myVec2.setY(-5.4321);
	myVec2.setZ(7.8910);
	std::cout << myVec2 << "\n";

	Vec3 myVec3;
	myVec3 = myVec2;
	std::cout << myVec3 << "\n";

	return 0;
}