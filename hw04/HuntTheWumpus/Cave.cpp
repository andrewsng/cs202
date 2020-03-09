/*
Cave.cpp
Andrew Ng
Feb 5, 2020
Source code for Cave class
*/



#include "Cave.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <sstream>
#include <iomanip>


Cave::CaveNode::CaveNode(int id) : nodeId(id), numConnected(0), visited(0)
{
	shortDesc = "short desc.";
	longDesc = "long description";
}


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


void Cave::genCave() {
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


void Cave::setWumpus(const int& wRoom) {
	wumpus = wRoom;
}


void Cave::setPit(const int& pRoom) {
	pit = pRoom;
}


void Cave::setBat(const int& bRoom) {
	bat = bRoom;
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
		std::cout << "Moving to new room: \n";
		std::cout << newLocation << " ";
		if (caveRooms[newLocation].visited) {
			printShortDesc(newLocation);
		}
		else {
			printLongDesc(newLocation);
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


void Cave::printAdjacent(bool shortdesc) const
{
	auto idVec = &caveRooms[currentRoom].connIds;
	for (int i = 0; i < idVec->size(); ++i) {
		if (i == idVec->size() - 1) {
			std::cout << ", and ";
		}
		else if (i > 0) {
			std::cout << ", ";
		}
		std::cout << (*idVec)[i];
	}
	std::cout << "\n\n";
	std::cout << "You observe: \n";

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
	std::cout << "\n\n";
}


void Cave::printShortDesc(int room) const
{
	std::cout << "(" << caveRooms[room].shortDesc << ")";
}


void Cave::printLongDesc(int room) const
{
	std::cout << "(" << caveRooms[room].longDesc << ")";
}


void Cave::saveRooms(std::ofstream& fout) const
{
	fout << currentRoom << "\n";
	for (auto r : caveRooms) {
		fout << r.nodeId << "\n";
		fout << r.numConnected << "\n";
		fout << r.shortDesc << "\n";
		fout << r.longDesc << "\n";
		for (auto c : r.connIds) {
			fout << c << " ";
		}
		fout << "\n";
	}
}


void Cave::readRooms(std::ifstream& fin)
{
	caveRooms.clear();
	fin >> currentRoom;
	while (true) {
		int newId;
		fin >> newId;
		if (!fin) {
			if (fin.eof()) {
				break;
			}
			else {
				std::cout << "Could not read line\n";
				break;
			}
		}
		CaveNode newNode(newId);
		fin >> newNode.numConnected;
		fin.ignore(99999, '\n');
		std::getline(fin, newNode.shortDesc);
		std::getline(fin, newNode.longDesc);
		for (int i = 0; i < newNode.numConnected; ++i) {
			int connId;
			fin >> connId;
			(newNode.connIds).push_back(connId);
		}
		caveRooms.push_back(newNode);
	}
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