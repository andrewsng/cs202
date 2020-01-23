#include <iostream>
#include <vector>
#include "Jumpsuit.h"


void clearColor(Jumpsuit& j)
{
	j.clear();
}


void printColor(const Jumpsuit& j)
{
	std::cout << "Color is: " << j.getColor() << "\n";
}


int main()
{
	Jumpsuit suit1;
	Jumpsuit suitCopy(suit1);
	Jumpsuit blueSuit("blue");
	std::cout << "\n";

	suitCopy.setJumpsuit(blueSuit);
	std::cout << "\n";

	printColor(suit1);
	printColor(suitCopy);
	printColor(blueSuit);
	std::cout << "\n";

	std::vector<Jumpsuit> suits(5);
	std::cout << "\n";
}