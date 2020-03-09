/*
Spelunking.cpp
Andrew Ng
Feb 5, 2020
Cave spelunking main menu
*/



#include <iostream>
#include <fstream>
#include "Cave.h"


using std::cin;
using std::cout;
using std::endl;


int main()
{
	Cave newCave(20);
	while (true) {
		int status = newCave.updateGame();
		int location = newCave.getCurrentRoom();
		if (status == 0) {
			cout << "The Wumpus killed you!\nGAME OVER...\n";
			break;
		}
		if (status == 1) {
			cout << "You fell into the bottomless pit!\nGAME OVER...\n";
			break;
		}
		if (status == 3) {
			cout << "You ran out of arrows and the Wumpus found you!\n"
				<< "GAME OVER...\n";
			break;
		}
		cout << "You are in room " << location << ".\n";
		std::cout << "There are tunnels to rooms ";
		newCave.printAdjacent();

		cout << "Would you like to move or shoot?\n"
			<< "1. Move to adjacent room\n"
			<< "2. Shoot arrow\n"
			<< "3. Print Game State (for debug)\n"
			<< "4. Exit program\n" << endl;

		
		int option;
		cin >> option;
		switch (option) {
		case 1:
			newCave.gotoAdjacentRoom();
			continue;
		case 2:
			if (newCave.shootArrow()) {
				cout << "Your arrow hit and killed the Wumpus!\nYOU WIN!\n";
				return 0;
			}
			continue;
		case 3:
			newCave.printConnections();
			continue;
		case 4:
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
	return 0;
}