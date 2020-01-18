#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>


using std::cout;
using std::endl;
using std::string;
using std::vector;


double cpp_ftoc(const char* str)
{
	double result;
	std::istringstream istr(str);
	istr >> result;
	if (!istr) {
		cout << "ERROR: Could not read temperature value" << endl;
		return -9999;
	}
	return (result - 32.0) * (5.0 / 9.0);
}


double c_ctof(const char* str)
{
	char* err;
	double result = strtod(str, &err);
	if (*err != 0) {
		cout << "ERROR: Could not read temperature value" << endl;
		return -9999;
	}
	return result * (9.0 / 5.0) + 32.0;
}


int main(int argc, char** argv)
{
	if (argc >= 3) {
		if (argv[1] == string("--ftoc")) {
			double result = cpp_ftoc(argv[2]);
			if (result == -9999) {
				return 0;
			}
			cout << result << endl;
		}
		else if (argv[1] == string("--ctof")) {
			double result = c_ctof(argv[2]);
			if (result == -9999) {
				return 0;
			}
			cout << result << endl;
		}
		else {
			cout << "ERROR: Argument not found\n"
				 << "Available functions: --ftoc, --ctof" << endl;
		}
	}
}