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
	/*std::ofstream fout("caveout.txt");
	if (!fout) {
		cout << "Could not write to file\n";
		return 0;
	}
	std::ifstream fin("cavein.txt");
	if (!fin) {
		cout << "Could not read file\n";
		return 0;
	}*/
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
		cout << "You are in room " << location << ".\n";
		std::cout << "There are tunnels to rooms ";
		newCave.printAdjacent(1);

		cout << "What would you like to do?\n"
			<< "1. Move to adjacent room\n"
			<< "2. Print long description\n"
			<< "3. Save Cave\n" 
			<< "4. Open Cave\n" 
			<< "5. Print Connections\n"
			<< "6. Exit program\n" << endl;

		
		int option;
		cin >> option;
		switch (option) {
		case 1:
			newCave.gotoAdjacentRoom(location);
			continue;
		case 2:
			cout << location << " ";
			newCave.printLongDesc(location);
			cout << "\nConnected to: \n";
			newCave.printAdjacent(0);
			continue;
		case 3:
			cout << "Saving cave...\n";
			//newCave.saveRooms(fout);
			continue;
		case 4:
			cout << "Opening cave...\n";
			//newCave.readRooms(fin);
			continue;
		case 5:
			newCave.printConnections();
			continue;
		case 6:
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