#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>


using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;


bool LineToTokens(const string& line, vector<string>& tokens)
{
	std::istringstream iss(line);
	string token;
	while (true) {
		iss >> token;
		if (!iss) {
			break;
		}
		tokens.push_back(token);
	}
	return 1;
}


bool ReadLine(std::istream& is, vector<string>& tokens,
	vector<pair<int, int>>& linecols)
{
	string line;
	std::getline(is, line);
	if (line.empty()) {
		tokens.push_back("blank line");
	}
	else {
		LineToTokens(line, tokens);
	}
	
	return 1;
}


void PrintTokens(std::ostream& os, const vector<string>& tokens,
	const vector<pair<int, int>>& linecols)
{
	for (auto t : tokens) {
		cout << t << "\n";
	}
}


int main(int argc, char** argv)
{
	vector<string> tokens;
	vector<pair<int, int>> linecols;

	for (int i = 0; i < 3; ++i) {
		ReadLine(std::cin, tokens, linecols);
	}
	PrintTokens(cout, tokens, linecols);
}