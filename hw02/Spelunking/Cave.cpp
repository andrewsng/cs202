#include "Cave.h"
#include <random>


Cave::CaveNode::CaveNode(int id) : nodeId(id), numConnected(0)
{
	for (auto r : rooms) {
		r = std::weak_ptr<CaveNode>();
	}

	shortDesc = "default short description";
	longDesc = "default long description";
}


Cave::Cave(int size)
{
	currentRoom = 1;

	for (int i = 0; i < size; ++i) {
		caveRooms.push_back(std::make_shared<CaveNode>(i + 1));
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, size);

	for (size_t i = 0; i < caveRooms.size(); ++i) {
		while (true) {
			int randId = dist(gen);
			if (randId = i + 1) {
				continue;
			}
			else if (caveRooms[randId - 1]->numConnected == MaxAdjacentRooms) {
				continue;
			}
			else {
				connect(i + 1, randId);
			}
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