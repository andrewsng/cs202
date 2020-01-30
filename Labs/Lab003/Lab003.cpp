#include <iostream>
#include <memory>
#include "Jumpsuit.h"


using std::cout;
using std::endl;


int main()
{
	cout << "Creating raw pointer.\n";
	Jumpsuit* jPtr = new Jumpsuit;


	cout << "\nCreating unique_ptr.\n";
	auto uPtr1 = std::make_unique<Jumpsuit>("red");
	
	cout << "\nTransferring ownership to new unique pointer.\n";
	auto uPtr2 = std::move(uPtr1);

	cout << "\nCalling a member function.\n";
	uPtr2->setColor("green");

	cout << "\nCreating shared_ptr.\n";
	auto sPtr1 = std::make_shared<Jumpsuit>("blue");

	cout << "\nCreating another shared_ptr to the same object.\n\n";
	auto sPtr2 = sPtr1;
}