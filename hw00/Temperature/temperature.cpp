#include <iostream>
#include <string>
#include <vector>


using std::cout;
using std::endl;
using std::string;
using std::vector;


double cpp_ftoc(const char* str)
{

}


double c_ctof(const char* str)
{

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