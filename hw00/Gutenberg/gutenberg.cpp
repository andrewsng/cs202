/*
Andrew Ng
gutenberg.cpp
Jan 19, 2020
Project Gutenberg excerpt
program for hw00
*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>


using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;


int main()
{
	cout << "An excerpt from:\n"
		<< "A Tale of Two Cities by Charles Dickens" << endl;

	// book txt file input
	ifstream fin("TaleOfTwoCities.txt");
	if (!fin) {
		cout << "ERROR: Book could not be read" << endl;
		return 0;
	}

	// loop that separates out paragraphs into vector
	string line;
	string excerpt;
	vector<string> excerpts;
	while (true) {
		std::getline(fin, line);
		if (!fin) {
			if (fin.eof()) {
				excerpts.push_back(excerpt);
				break;
			}
			else {
				cout << "ERROR: Could not read line" << endl;
				return 0;
			}
		}
		if (line.empty()) {
			if (excerpt.empty()) {
				continue;
			}
			excerpts.push_back(excerpt);
			excerpt.clear();
		}
		else {
			excerpt = excerpt + '\n' + line;
		}
	}

	// random number generator to pick index of excerpt
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(2, 1500);
	int index;
	while (true) {
		index = dist(gen);
		if (excerpts[index].size() < 300) {
			continue;
		}
		break;
	}

	// print excerpt and random index
	cout << "\nExcerpt chosen: " << index << "/3317\n"
		<< excerpts[index] << endl;
}