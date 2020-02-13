#include "names.h"


int x = 10;


void foo() {
	std::cout << "In global foo(), x is: " << x << "\n";
}


int main()
{
	neat::foo();
	foo();
}