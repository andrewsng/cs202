/*
	Lab009.cpp
	Andrew Ng
	Apr 4, 2020
	lab 9 for cs202
*/


#include <iostream>


class TestStatic
{
public:
	TestStatic() {
		std::cout << "object " << objCount_ << " constructed\n";
		objCount_++;
	}

private:
	static int objCount_;
};

int TestStatic::objCount_{ 0 };


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

	TestStatic ts1;
	TestStatic ts2;
	TestStatic ts3;
	TestStatic ts4;
}