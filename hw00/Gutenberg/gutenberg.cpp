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

	ifstream fin("TaleOfTwoCities.txt");
	if (!fin) {
		cout << "ERROR: Book could not be read" << endl;
		return 0;
	}
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
	cout << "\nExcerpt chosen: " << index << "/3317\n"
		<< excerpts[index] << endl;
}