/*
Cave.h
Andrew Ng
Mar 8, 2020
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

	int updateGame();

	void getAdj(std::vector<int>& reach,
		const int& current);

	bool shootArrow();

	int size() const;

	int getCurrentRoom() const;

	void gotoRoom(int room);

	void gotoAdjacentRoom();

	void connect(int r1, int r2);

	void printAdjacent() const;

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
	};

	std::vector<Cave::CaveNode> caveRooms;
	
	int currentRoom;

	int wumpus;

	int pit;

	int bat;

	int arrows = 5;
};


#endif