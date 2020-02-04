#include "Cave.h"
#include <iostream>
#include <random>


Cave::CaveNode::CaveNode() : nodeId(0), numConnected(0)
{
	//for (auto r : rooms) {
	//r = std::make_shared<CaveNode>();
	//}

	for (int i = 0; i < MaxAdjacentRooms; ++i) {
		connIds.push_back(0);
	}

	shortDesc = "default short description";
	longDesc = "default long description";
}


Cave::Cave(int size)
{
	std::vector<CaveNode> caveRooms;

	currentRoom = 1;

	std::cout << "made it\n";

	for (int i = 0; i < size; ++i) {
		std::cout << i << "\n";
		Cave::CaveNode newNode;
		caveRooms.push_back(newNode);
	}

	for (auto c : caveRooms) {
		std::cout << "id: " << c.nodeId << "\n";
	}

	std::cout << "made it2\n";

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, size-1);

	for (int i = 0; i < caveRooms.size(); ++i) {
		int randId = dist(gen);
		if (randId == i) {

		}
		else if (caveRooms[randId].numConnected == MaxAdjacentRooms) {
			
		}
		else {
			connect(i, randId);
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

}

void Cave::connect(int room1, int room2)
{

}