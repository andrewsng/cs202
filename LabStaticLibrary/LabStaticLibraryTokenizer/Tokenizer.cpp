/*
Tokenizer.cpp
Andrew Ng
Feb 16, 2020
Simple Tokenizer program
for HW3
*/


#pragma comment(lib, "LabStaticLibrary.lib")

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Stopwatch.h"


using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;


bool lineOnly;


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
	if (!is) {
		return 0;
	}

	int sizeDiff = tokens.size();
	if (line.empty()) {
		line = "blank line";
		tokens.push_back("blank line");
	}
	else {
		LineToTokens(line, tokens);
	}
	if (lineOnly) {
		return 1;
	}
	sizeDiff = tokens.size() - sizeDiff;

	int lineNum;
	if (linecols.empty()) {
		lineNum = 1;
	}
	else {
		lineNum = linecols.back().first + 1;
	}

	int colNum = 0;
	for (auto it = tokens.end() - sizeDiff; it < tokens.end(); ++it) {
		colNum = line.find(*it, colNum);

		linecols.push_back(std::make_pair(lineNum, colNum + 1));

		colNum += (*it).size();
	}

	return 1;
}


void PrintTokens(std::ostream& os, const vector<string>& tokens,
	const vector<pair<int, int>>& linecols)
{
	for (size_t i = 0; i < tokens.size(); ++i) {
		cout << "Line " << std::setw(5) << linecols[i].first << ", ";
		cout << "Column " << std::setw(4) << linecols[i].second << ": ";
		cout << "\"" << tokens[i] << "\"\n";
	}
}


int main(int argc, char** argv)
{
	if (argc >= 3) {
		if (argv[2] == string("--lineonly")) {
			lineOnly = 1;
		}
		else {
			lineOnly = 0;
		}
	}

	vector<string> tokens;
	vector<pair<int, int>> linecols;
	//std::ifstream fin(argv[1]);
	std::ifstream fin("n16berry.txt");
	if (!fin) {
		cout << "Error opening file\n";
		return -1;
	}

	fin.seekg(0, fin.end);
	size_t fileSize = fin.tellg();
	fin.seekg(0, fin.beg);

	bool run = 1;
	Stopwatch duration;
	while (run) {
		run = ReadLine(fin, tokens, linecols);
	}

	if (lineOnly) {
		cout << "\nLineOnly Time: \n";
	}
	else {
		PrintTokens(cout, tokens, linecols);
		cout << "\nReadLines/PrintTokens Time: \n";
	}

	duration.stop();
	duration.reportMilli();
	duration.reportSec();

	cout << "\nFile Size: " << fileSize << " bytes" << endl;
}