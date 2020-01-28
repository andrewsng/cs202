#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>
#include "Stopwatch.h"


using std::cout;
using std::endl;
using std::string;
using std::list;
using std::vector;
using std::map;


int main()
{
	std::ifstream fin("TaleOfTwoCities.txt");
	if (!fin) {
		cout << "ERROR: Book could not be read" << endl;
		return 0;
	}

	string word;
	list<string> bookList;
	vector<string> bookVec;
	map<string, unsigned int, std::greater<string>> bookMap;
	while (true) {
		fin >> word;
		if (!fin) {
			if (fin.eof()) {;;
				break;
			}
			else {
				cout << "ERROR: Could not read word" << endl;
				return 0;
			}
		}
		else {
			bookList.push_back(word);
			bookVec.push_back(word);
			bookMap[word] = 1;
		}
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, bookVec.size());

	int index = dist(gen) - 1;
	string randStr = bookVec[index];
	
	cout << "Algorithm: Sort (list)\n";
	bookList.sort();

	cout << "Algorithm: Find (list)\n";
	auto listIter = std::find(bookList.begin(), bookList.end(), randStr);

	cout << "Algorithm: Sort (vector)\n";
	std::sort(bookVec.begin(), bookVec.end());

	cout << "Algorithm: Find (vector)\n";
	auto vecIter = std::find(bookVec.begin(), bookVec.end(), randStr);

	cout << "Algorithm: Sort (map)\n";
	Stopwatch mapSort;
	map<string, unsigned int, std::less<string>> bookMapS(bookMap.begin(), bookMap.end());
	mapSort.stop();
	mapSort.reportSec();
	mapSort.reportMilli();

	cout << "Algorithm: Find (map)\n";
	auto mapIter = bookMap.find(randStr);


	int listIndex = std::distance(bookList.begin(), listIter);
	int vecIndex = vecIter - bookVec.begin();
	int mapIndex = std::distance(bookMap.begin(), mapIter);

	cout << "\n";
	cout << randStr << "\n";
	cout << "List found: " << *listIter << listIndex << "\n";
	cout << "Vector found: " << *vecIter << vecIndex << "\n";
	cout << "Map found: " << mapIter->first << mapIndex << "\n";
	cout << bookList.size() << "\n";
	cout << bookVec.size() << "\n";
	cout << bookMap.size() << "\n";

	/*
	for (auto w : bookMapS) {
		cout << w.first << " ";
	}
	*/
}