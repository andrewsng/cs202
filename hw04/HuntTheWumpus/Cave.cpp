/*
Cave.cpp
Andrew Ng
Mar 8, 2020
Source code for Cave class
*/


#include "Cave.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <sstream>
#include <iomanip>


Cave::CaveNode::CaveNode(int id) : nodeId(id), numConnected(0), visited(0)
{}


Cave::Cave(int size)
{
	currentRoom = 0;

	for (int i = 0; i < size; ++i) {
		Cave::CaveNode newNode(i);
		caveRooms.push_back(newNode);
	}

	genCave();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, size - 1);
	int newWump = dist(gen);
	int newPit;
	int newBat;
	setWumpus(newWump);
	while (true) {
		newPit = dist(gen);
		if (newPit == newWump) {
			continue;
		}
		break;
	}
	setPit(newPit);
	while (true) {
		newBat = dist(gen);
		if (newBat == newWump || newBat == newPit) {
			continue;
		}
		break;
	}
	setBat(newBat);
}


void Cave::genCave()
{
	int size = caveRooms.size();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::vector<double> prob(size, 1.0);

	int index = 0;
	int fails = 0;
	while (true) {
		if (std::count(prob.begin(), prob.end(), 0.0) == prob.size()) {
			break;
		}
		std::discrete_distribution<int> dist(prob.begin(), prob.end());
		if (fails >= (2 * size)) {
			break;
		}
		if (index == size) {
			index = 0;
		}
		int randId = dist(gen);
		auto idPtr = &(caveRooms[index].connIds);
		if (caveRooms[index].numConnected == MaxAdjacentRooms) {
			prob[index] = 0.0;
			index++;
			continue;
		}
		if (caveRooms[randId].numConnected == MaxAdjacentRooms) {
			prob[randId] = 0.0;
			continue;
		}
		if (randId == index) {
			fails++;
			continue;
		}
		else if (std::count(idPtr->begin(), idPtr->end(), randId)) {
			fails++;
			continue;
		}
		else {
			this->connect(index, randId);
			fails = 0;
		}
		int fb = fails;
		for (auto p : prob) {
			if (p != 0.0) {
				fails++;
				break;
			}
		}
		if (fb == fails) {
			break;
		}
	}
}


void Cave::setWumpus(const int& wRoom)
{
	wumpus = wRoom;
}


void Cave::setPit(const int& pRoom)
{
	pit = pRoom;
}


void Cave::setBat(const int& bRoom)
{
	bat = bRoom;
}


int Cave::updateGame()
{
	int size = caveRooms.size();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::vector<double> prob(size, 1.0);

	if (arrows == 0) {
		return 3;
	}

	if (currentRoom == wumpus) {
		return 0;
	}

	if (currentRoom == pit) {
		return 1;
	}

	if (currentRoom == bat) {
		prob[currentRoom] = 0.0;
		std::discrete_distribution<int> dist(prob.begin(), prob.end());
		gotoRoom(dist(gen));
		prob[wumpus] = 0.0;
		prob[pit] = 0.0;
		dist = std::discrete_distribution<int>(prob.begin(), prob.end());
		setBat(dist(gen));
		if (updateGame() == 0) {
			std::cout << "The giant bat moves you to the Wumpus' room.\n\n";
			return 0;
		}
		if (updateGame() == 1) {
			std::cout << "The giant bat moves you over the bottomless pit.\n\n";
			return 1;
		}
		std::cout << "The giant bat moves you to another room.\n\n";
		return 2;
	}
	return -1;
}


void Cave::getAdj(std::vector<int>& reach, const int& current) {
	auto idPtr = &(caveRooms[current].connIds);
	for (auto c : *idPtr) {
		reach.push_back(c);
	}
}


bool Cave::shootArrow()
{
	while (true) {
		std::cout << "Enter a target room to shoot the arrow at.\n"
			<< "The room must be at most 3 rooms away.\n";
		int target;
		std::cin >> target;
		if (!std::cin) {
			std::cout << "Not an available option.\n";
			std::cin.clear();
			std::cin.ignore(99999, '\n');
			continue;
		}

		std::vector<int> reachable;
		getAdj(reachable, currentRoom);
		int currentSize = reachable.size();
		for (int i = 0; i < currentSize; ++i) {
			getAdj(reachable, reachable[i]);
		}
		currentSize = reachable.size();
		for (int i = 0; i < currentSize; ++i) {
			getAdj(reachable, reachable[i]);
		}

		if (std::count(reachable.begin(), reachable.end(), target) == 0) {
			std::cout << "Target is too far.\n";
			continue;
		}
		std::cout << "\n";
		if (target == wumpus) {
			return true;
		}

		auto idPtr = &(caveRooms[wumpus].connIds);
		std::random_device rd;
		std::mt19937 gen(rd());
		std::vector<double> prob(caveRooms.size(), 0.0);
		for (auto i : *idPtr) {
			prob[i] = 1.0;
		}
		std::discrete_distribution<int> dist(prob.begin(), prob.end());
		setWumpus(dist(gen));
		std::cout << "The arrow missed and the Wumpus has awoken.\n"
			<< "The Wumpus will move to an adjacent room.\n\n";
		arrows--;
		break;
	}
	return false;
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


void Cave::gotoAdjacentRoom()
{
	while (true) {
		std::cout << "Enter an adjacent room # to move there.\n";
		int newLocation;
		std::cin >> newLocation;
		auto idPtr = &(caveRooms[currentRoom].connIds);
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
		std::cout << "\n\n";
		gotoRoom(newLocation);
		caveRooms[newLocation].visited = 1;
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
	auto idVec = &caveRooms[currentRoom].connIds;
	for (int i = 0; i < idVec->size(); ++i) {
		if (i != 0) {
			if (i == idVec->size() - 1) {
				std::cout << ", and ";
			}
			else if (i > 0) {
				std::cout << ", ";
			}
		}
		std::cout << (*idVec)[i];
	}
	std::cout << "\n\n";

	for (auto c : *idVec) {
		if (c == wumpus) {
			std::cout << "\"I smell a wumpus...\"\n";
		}
		if (c == pit) {
			std::cout << "\"I feel a breeze...\"\n";
		}
		if (c == bat) {
			std::cout << "\"I hear a bat...\"\n";
		}
	}
	std::cout << "\n";
}


void Cave::printConnections() const
{
	int size = caveRooms.size();
	for (int j = 0; j < size; ++j) {
		if (j == 0) {
			std::cout << "   ";
			for (int i = 0; i < size; ++i) {
				std::cout << std::setw(3) << i;
			}
			std::cout << "\n";
		}
		std::cout << std::setw(3) << j;
		for (int i = 0; i < size; ++i) {
			std::cout << std::setw(3) << this->checkConnect(j, i);
		}
		if (j == wumpus) {
			std::cout << " W";
		}
		if (j == pit) {
			std::cout << " P";
		}
		if (j == bat) {
			std::cout << " B";
		}
		std::cout << "\n";
	}
}


bool Cave::checkConnect(int room1, int room2) const {
	auto ptr1 = &caveRooms[room1].connIds;
	auto ptr2 = &caveRooms[room2];
	if (std::count(ptr1->begin(), ptr1->end(), ptr2->nodeId) == 1) {
		return 1;
	}
	return 0;
}