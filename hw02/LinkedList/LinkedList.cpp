/*
LinkedList.cpp
Andrew Ng
Feb 2, 2020
Linked list functions
tested using catch2 for hw2
*/


#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <algorithm>


using std::cout;
using std::endl;
using std::string;
using std::list;
using std::shared_ptr;


struct Skill
{
	Skill() : name_("Empty"), type_("Empty"), damage_(0), 
			  cost_(0), range_(0), attackTime_(0.0)
	{};

	Skill(const string& nn, const string& nt, const int& nd, 
		  const int& nc, const int& nr, const double& nat) :
		  name_(nn), type_(nt), damage_(nd), 
		  cost_(nc), range_(nr), attackTime_(nat)
	{};

	string name_;
	string type_;
	int damage_;
	int cost_;
	int range_;
	double attackTime_;
};


void printList(const list<shared_ptr<Skill>>& list) {
	for (auto v : list) {
		cout << (*v).name_ << " - ";
		cout << (*v).type_ << " - ";
		cout << (*v).damage_ << " damage - ";
		cout << (*v).cost_ << " mana cost - ";
		cout << (*v).range_ << " range - ";
		cout << (*v).attackTime_ << "s attack time\n";
	}
	cout << "\n";
}


TEST_CASE("Linked List Operations", "[LinkedList]") {
	
	// the list
	list<std::shared_ptr<Skill>> testList;


	// push_back function test
	shared_ptr<Skill> sPtr1 = std::make_shared<Skill>
		("Axe Throw", "Attack", 190, 0, 7, 0.5);
	shared_ptr<Skill> sPtr2 = std::make_shared<Skill>
		("Fireball", "Spell", 250, 40, 10, 0.8);
	testList.push_back(sPtr1);
	testList.push_back(sPtr2);
	cout << "--Skills pushed to back--\n";
	printList(testList);
	REQUIRE((*testList.back()).name_ == "Fireball");


	// pop_front function test
	cout << "--Front Popped--\n";
	testList.pop_front();
	printList(testList);
	REQUIRE((*testList.front()).name_ == "Fireball");


	shared_ptr<Skill> sPtr3 = std::make_shared<Skill>
		("Lightning Bolt", "Spell", 150, 20, 5, 0.3);
	shared_ptr<Skill> sPtr4 = std::make_shared<Skill>
		("Poison Arrow", "Attack", 170, 0, 11, 0.4);
	testList.push_back(sPtr3);
	testList.push_back(sPtr4);
	cout << "--Skills pushed to back--\n";
	printList(testList);
	REQUIRE((*testList.back()).name_ == "Poison Arrow");


	// pop_back function test
	cout << "--Back Popped--\n";
	testList.pop_back();
	printList(testList);
	REQUIRE((*testList.back()).name_ == "Lightning Bolt");


	// find function test
	shared_ptr<Skill> searchPtr = sPtr3;
	auto iter = find(testList.begin(), testList.end(), searchPtr);
	REQUIRE((*(*iter)).name_ == "Lightning Bolt");

	searchPtr = sPtr4;
	iter = find(testList.begin(), testList.end(), searchPtr);
	REQUIRE(iter == testList.end());


	// insert function test
	shared_ptr<Skill> insertPtr = std::make_shared<Skill>
		("Ice Spear", "Spell", 230, 30, 3, 0.4);

	auto iter2 = std::find_if(testList.begin(), testList.end(),
		[&](shared_ptr<Skill> v) {
			return (*v).name_ > (*insertPtr).name_;
		});
	testList.insert(iter2, insertPtr);

	REQUIRE((*(*std::prev(iter2))).name_ == "Ice Spear");
	cout << "--Skill Inserted in Sorted Spot--\n";
	printList(testList);

}