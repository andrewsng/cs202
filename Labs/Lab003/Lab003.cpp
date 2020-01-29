#include <iostream>
#include <memory>
#include "Jumpsuit.h"


using std::cout;
using std::endl;


int main()
{
	cout << "Creating raw pointer.\n";
	Jumpsuit* jPtr = new Jumpsuit("blue");


	cout << "Creating unique_ptr.\n";
	auto uPtr1 = std::make_unique<Jumpsuit>("green");
	
	cout << "Transferring ownership to new unique pointer.\n";
	auto uPtr2 = std::move(uPtr1);

	cout << "Calling a member function.\n";
	uPtr2->setColor("red");

	cout << "Creating shared_ptr.\n";
	auto jPtr1 = std::make_shared<Jumpsuit>("yellow");

	cout << "Creating another shared_ptr to the same object.\n";
	auto jPtr2 = jPtr1;
}