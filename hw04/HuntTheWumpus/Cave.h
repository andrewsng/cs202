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

	// what is the number of rooms in the cave?

	int size() const;

	// return current room

	int getCurrentRoom() const;

	// go to room in the cave complex

	void gotoRoom(int room);

	// which adjacent room? 0, 1, or 2?

	void gotoAdjacentRoom(int room);

	// connect two rooms together

	void connect(int r1, int r2);

	void printAdjacent(bool shortdesc) const;

	// print the short description of the room

	void printShortDesc(int room) const;

	// print the long description of the room

	void printLongDesc(int room) const;

	// save rooms to an output stream

	void saveRooms(std::ofstream& fout) const;

	// read rooms from an input stream

	void readRooms(std::ifstream& fin);

	void printConnections() const;

private:

	static constexpr int MaxAdjacentRooms = 3;

	struct CaveNode {
		int nodeId;

		int numConnected;

		bool visited;

		std::vector<int> connIds;

		std::string shortDesc; // a short description of this room

		std::string longDesc; // a long description of this room

		CaveNode(int id);

	};

	std::vector<Cave::CaveNode> caveRooms;
	
	int currentRoom;

};


#endif