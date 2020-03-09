/*
Cave.h
Andrew Ng
Feb 5, 2020
Header for Cave class
*/



#pragma once

#ifndef CAVE_H
#define CAVE_H


#include <string>
#include <vector>
#include <memory>
#include <fstream>


class Cave {
public:
	
	Cave(int size);

	void genCave();

	void setWumpus(const int& wRoom);

	void setPit(const int& pRoom);

	void setBat(const int& bRoom);

	int size() const;

	int getCurrentRoom() const;

	void gotoRoom(int room);

	void gotoAdjacentRoom(int room);

	void connect(int r1, int r2);

	void printAdjacent(bool shortdesc) const;

	void printShortDesc(int room) const;

	void printLongDesc(int room) const;

	void saveRooms(std::ofstream& fout) const;

	void readRooms(std::ifstream& fin);

	void printConnections() const;

	bool checkConnect(int room1, int room2) const;

private:

	static constexpr int MaxAdjacentRooms = 3;

	struct CaveNode {
		CaveNode(int id);

		int nodeId;

		int numConnected;

		bool visited;

		std::vector<int> connIds;

		std::string shortDesc; // a short description of this room

		std::string longDesc; // a long description of this room
	};

	std::vector<Cave::CaveNode> caveRooms;
	
	int currentRoom;

	int wumpus;

	int pit;

	int bat;
};


#endif