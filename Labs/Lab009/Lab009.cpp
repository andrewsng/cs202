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

	static void printCount() {
		std::cout << objCount_ << " TestStatic objects have been constructed\n";
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

	std::cout << "\n";

	TestStatic ts1;
	TestStatic::printCount();
	TestStatic ts2;
	TestStatic::printCount();
	TestStatic ts3;
	TestStatic ts4;
	TestStatic::printCount();
}