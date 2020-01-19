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
	for (auto e : excerpts) {
		cout << e << '\n';
	}
	cout << excerpts.size() << " TEST END" << endl;
}