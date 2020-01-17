#include <iostream>
#include <string>
#include <sstream>
#include <vector>


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
	return 0.0;
}


int main(int argc, char** argv)
{
	if (argc == 4) {
		if (argv[2] == string("--ftoc")) {
			double result = cpp_ftoc(argv[3]);
			if (result == -9999) {
				return 0;
			}
			cout << result << endl;
		}
	}
}