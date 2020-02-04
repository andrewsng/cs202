#include "Cave.h"
#include <iostream>
#include <random>


Cave::CaveNode::CaveNode(int id)
{
	nodeId = id;

	numConnected = 0;

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
		Cave::CaveNode newNode(i);
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

void Cave::connect(int r1, int r2)
{
	auto it1 = caveRooms.begin() + r1;
	auto it2 = caveRooms.begin() + r2;
	std::cout << "test\n";
	std::cout << r1 << " " << r2 << "\n";
	int n1 = (*it1).numConnected;
	int n2 = (*it2).numConnected;
	std::cout << n1 << " " << n2 << "\n";

	(caveRooms[r1].connIds).push_back(r2);
	(caveRooms[r2].connIds).push_back(r1);

	caveRooms[r1].numConnected++;
	caveRooms[r2].numConnected++;
}