#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;


bool LineToTokens(const string& line, vector<string>& tokens)
{
	return 1;
}


bool ReadLine(std::istream& is, vector<string>& tokens,
	vector<pair<int, int>>& linecols)
{
	string line;
	std::getline(is, line);

	return 1;
}


void PrintTokens(std::ostream& os, const vector<string>& tokens,
	const vector<pair<int, int>>& linecols)
{

}


int main(int argc, char** argv)
{
	vector<string> tokens;
	vector<pair<int, int>> linecols;

	ReadLine(std::cin, tokens, linecols);
}