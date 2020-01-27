#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
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
		}
	}

	bookList.sort();

	std::sort(bookVec.begin(), bookVec.end());

	for (auto w : bookVec) {
		cout << w << " ";
	}
}