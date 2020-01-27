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

	bookList.sort();

	std::sort(bookVec.begin(), bookVec.end());

	Stopwatch mapSort;
	map<string, unsigned int, std::less<string>> bookMapS(bookMap.begin(), bookMap.end());
	mapSort.stop();
	mapSort.reportSec();
	mapSort.reportMilli();

	for (auto w : bookMapS) {
		cout << w.first << " ";
	}
}