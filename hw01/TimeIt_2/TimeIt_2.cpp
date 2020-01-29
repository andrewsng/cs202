/*
TimeIt_2.cpp
Andrew Ng
Jan 26, 2020
main setup for measuring books
and algorithms
*/


#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include "Stopwatch.h"


using std::cout;
using std::endl;
using std::string;
using std::list;
using std::vector;
using std::map;


int main()
{
	vector<string> books{
		"TaleOfTwoCities.txt", 
		"AliceWonderland.txt",
		"Frankenstein.txt",
		"MobyDick.txt",
		"SherlockHolmes.txt"
	};

	for (auto b : books) {

		std::ifstream fin(b);
		if (!fin) {
			cout << "ERROR: Book could not be read" << endl;
			return 0;
		}

		cout << "Book file: " << b << "\n";

		string word;
		list<string> bookList;
		vector<string> bookVec;
		map<string, unsigned int, std::greater<string>> bookMap;

		cout << "Reading into containers:\n";

		Stopwatch readBook;
		while (true) {
			fin >> word;
			if (!fin) {
				if (fin.eof()) {
					;;
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
		readBook.stop();
		readBook.reportSec();
		readBook.reportMilli();

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(1, bookVec.size());

		int index = dist(gen) - 1;
		string randStr = bookVec[index];


		cout << "Algorithm: Sort (list)\n";

		Stopwatch listSort;
		bookList.sort();
		listSort.stop();
		listSort.reportSec();
		listSort.reportMilli();

		cout << "Algorithm: Find (list)\n";

		Stopwatch listFind;
		auto listIter = std::find(bookList.begin(), bookList.end(), randStr);
		listFind.stop();
		listFind.reportSec();
		listFind.reportMilli();


		cout << "Algorithm: Sort (vector)\n";

		Stopwatch vecSort;
		std::sort(bookVec.begin(), bookVec.end());
		vecSort.stop();
		vecSort.reportSec();
		vecSort.reportMilli();

		cout << "Algorithm: Find (vector)\n";

		Stopwatch vecFind;
		auto vecIter = std::find(bookVec.begin(), bookVec.end(), randStr);
		vecFind.stop();
		vecFind.reportSec();
		vecFind.reportMilli();


		cout << "Algorithm: Sort (map)\n";

		Stopwatch mapSort;
		map<string, unsigned int, std::less<string>> bookMapS(bookMap.begin(), bookMap.end());
		mapSort.stop();
		mapSort.reportSec();
		mapSort.reportMilli();

		cout << "Algorithm: Find (map)\n";

		Stopwatch mapFind;
		auto mapIter = bookMap.find(randStr);
		mapFind.stop();
		mapFind.reportSec();
		mapFind.reportMilli();


		cout << "\n";
	}
}