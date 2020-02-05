#include "Cave.h"
#include <iostream>
#include <random>
#include <algorithm>


Cave::CaveNode::CaveNode(int id)
{
	nodeId = id;

	numConnected = 0;

	shortDesc = "default short description";
	longDesc = "default long description";
}


Cave::Cave(int size)
{
	currentRoom = 1;

	for (int i = 0; i < size; ++i) {
		Cave::CaveNode newNode(i);
		caveRooms.push_back(newNode);
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, size-1);

	int index = 0;
	int fails = 0;
	while (true) {
		if (fails >= (2 * caveRooms.size())) {
			break;
		}
		if (index == caveRooms.size()) {
			index = 0;
		}
		int randId = dist(gen);
		auto idPtr = &(caveRooms[index].connIds);
		if (randId == index) {
			fails++;
			continue;
		}
		else if (std::count(idPtr->begin(), idPtr->end(), randId)) {
			fails++;
			continue;
		}
		else if (caveRooms[index].numConnected == MaxAdjacentRooms) {
			fails++;
			continue;
		}
		else if (caveRooms[randId].numConnected == MaxAdjacentRooms) {
			fails++;
			continue;
		}
		else {
			this->connect(index, randId);
			fails = 0;
			index++;
		}

	}

	for (auto r : caveRooms) {
		std::cout << "id: " << r.nodeId << "\n";
		std::cout << "connected to: \n";
		for (auto c : r.connIds) {
			std::cout << c << "\n";
		}
	}
}


int Cave::size() const
{
	return caveRooms.size();
}

int Cave::getCurrentRoom() const
{
	return currentRoom;
}

void Cave::gotoRoom(int room)
{
	currentRoom = room;
}

void Cave::gotoAdjacentRoom(int room)
{
	while (true) {
		std::cout << "Enter an adjacent room # to move there.\n";
		int newLocation;
		std::cin >> newLocation;
		auto idPtr = &(caveRooms[room].connIds);
		if (!std::cin) {
			std::cout << "Not an available option.\n";
			std::cin.clear();
			std::cin.ignore(99999, '\n');
			continue;
		}
		if (!std::count(idPtr->begin(), idPtr->end(), newLocation)) {
			std::cout << "Not an available option.\n";
			continue;
		}
		gotoRoom(newLocation);
		break;
	}
}

void Cave::connect(int r1, int r2)
{
	int n1 = (caveRooms[r1]).numConnected;
	int n2 = (caveRooms[r2]).numConnected;

	(caveRooms[r1].connIds).push_back(r2);
	(caveRooms[r2].connIds).push_back(r1);

	caveRooms[r1].numConnected++;
	caveRooms[r2].numConnected++;
}

void Cave::printAdjacent() const
{
	for (auto c : caveRooms[currentRoom].connIds) {
		std::cout << c << " ";
	}
	std::cout << "\n";
}

void Cave::printLongDesc(int room) const
{

}