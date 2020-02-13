#include "names.h"

namespace {
	int x = 5;
}

namespace neat
{
	void foo() {
		std::cout << "In neat::foo(), x is: " << x << "\n";
	}
}