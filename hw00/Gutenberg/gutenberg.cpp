#include <iostream>
#include <string>
#include <vector>
#include <fstream>


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
	for (int i = 0; i < 10; ++i) {
		std::getline(fin, line);
		excerpt += '\n' + line;
	}
	cout << excerpt << " TEST END" << endl;
}