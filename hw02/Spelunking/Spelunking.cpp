#include <iostream>
#include "Cave.h"


using std::cin;
using std::cout;
using std::endl;


int main()
{
	Cave newCave(15);
	while (true) {
		int location = newCave.getCurrentRoom();
		cout << "You are in room " << location << ".\n";
		std::cout << "Room " << location;
		std::cout << " is connected to:\n";
		newCave.printAdjacent();

		cout << "What would you like to do?\n"
			<< "1. Move to adjacent room\n"
			<< "2. Print long description\n"
			<< "3. Save Cave\n" 
			<< "4. Open Cave\n" 
			<< "5. Exit program\n" << endl;

		int option;
		cin >> option;
		switch (option) {
		case 1:
			newCave.gotoAdjacentRoom(location);
			continue;
		case 2:
			newCave.printLongDesc(location);
			continue;
		case 5:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Not an available option.\n";
			cin.clear();
			cin.ignore(99999, '\n');
			continue;
		}
		break;
	}
}