#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


void printSuits(const vector<string>& suits) {
	int i = 0;
	for (auto j : suits) {
		cout << i << ". " << j << endl;
		i++;
	}
}


void changeColor(vector<string>& suits) {
	cout << "Choose a suit to change its color" << endl;
	int num;
	cin >> num;
	if (suits[num] == "blank") {
		cout << "Enter a new color" << endl;
		string newColor;
		cin >> newColor;
		suits[num] = newColor;
		cout << "Color changed" << endl;
	}
	else {
		cout << "suit is not blank!" << endl;
	}
}


int main()
{
	vector<string> jumpsuits;

	for (int i = 0; i < 10; ++i) {
		jumpsuits.push_back("blank");
	}


	int choice;
	while (true) {
		cout << "What would you like to do?\n"
			<< "1. List jumpsuits\n"
			<< "2. Change jumpsuit color\n"
			<< "3. End program" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			printSuits(jumpsuits);
			continue;
		case 2:
			changeColor(jumpsuits);
			continue;
		case 3:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "default" << endl;
			continue;
		}
		break;
	}
}