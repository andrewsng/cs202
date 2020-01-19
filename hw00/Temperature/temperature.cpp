/*
Andrew Ng
temperature.cpp
Jan 19, 2020
temperature conversion program using 
command line arguments for hw00
*/


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>


using std::cout;
using std::endl;
using std::string;
using std::vector;


// converts F to C using C++ istringstream
double cpp_ftoc(const char* str)
{
	double result;
	std::istringstream istr(str);
	istr >> result;
	if (!istr) {
		return -9999;
	}
	return (result - 32.0) * (5.0 / 9.0);
}


// converts C to F using C strtod function
double c_ctof(const char* str)
{
	char* err;
	double result = strtod(str, &err);
	if (*err != 0) {
		return -9999;
	}
	return result * (9.0 / 5.0) + 32.0;
}


// prints out usage help
void printHelp()
{
	cout << "Available functions: --ftoc, --ctof\n"
		<< "ARGUMENT USAGE: <function name> <value>" << endl;
}


int main(int argc, char** argv)
{
	// checks if there are enough arguments
	if (argc >= 3) {

		// --ftoc argument given
		if (argv[1] == string("--ftoc")) {
			double result = cpp_ftoc(argv[2]);
			if (result == -9999) {
				cout << "ERROR: Could not read temperature value" << endl;
				return 0;
			}
			cout << result << endl;
		}

		// --ctof argument given
		else if (argv[1] == string("--ctof")) {
			double result = c_ctof(argv[2]);
			if (result == -9999) {
				cout << "ERROR: Could not read temperature value" << endl;
				return 0;
			}
			cout << result << endl;
		}
		else {
			cout << "ERROR: Argument not found" << endl;
			printHelp();
		}
	}
	else {
		cout << "ERROR: Not enough arguments" << endl;
		printHelp();
	}
}