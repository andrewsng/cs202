/*
	Lab009.cpp
	Andrew Ng
	Apr 4, 2020
	lab 9 for cs202
*/


#include <iostream>


void countMe()
{
	static int count = 0;
	count++;
	std::cout << __FUNCTION__ << " has been called " << count << " times\n";
}


int main()
{
	countMe();
	countMe();
	countMe();
	countMe();

}