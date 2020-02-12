#include <iostream>
#include <fstream>
#include <vector>


using std::cout;
using std::endl;


int main()
{
	std::ifstream fin("data.dat", std::ios::binary);
	
	std::vector<int> integers;
	while (true) {
		int i;
		fin.read(reinterpret_cast<char*>(&i), sizeof(int));
		if (!fin) {
			if (fin.eof()) {
				break;
			}
		}
		else {
			integers.push_back(i);
		}
	}

	int sum = 0;
	for (auto n : integers) {
		sum += n;
	}

	int average = sum / integers.size();

	cout << "Num of Ints: " << integers.size() << "\n";
	cout << "Sum: " << sum << "\n";
	cout << "Avg: " << average << "\n";
}