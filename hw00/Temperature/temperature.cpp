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
			cout << result << endl;
		}
	}
}