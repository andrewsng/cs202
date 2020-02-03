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


struct Value
{
	Value() : str1_("a"), str2_("a"), str3_("a"), int1_(0), int2_(0), int3_(0)
	{};

	Value(const string& ns1, const string& ns2, const string& ns3, const int& ni1, const int& ni2, const int& ni3)
	: str1_(ns1), str2_(ns2), str3_(ns3), int1_(ni1), int2_(ni2), int3_(ni3)
	{};

	string str1_;
	string str2_;
	string str3_;
	int int1_;
	int int2_;
	int int3_;
};


void printList(const list<shared_ptr<Value>>& list) {
	for (auto v : list) {
		cout << (*v).str1_ << "\n";
	}
	cout << "\n";
}


TEST_CASE("Linked List Operations", "[LinkedList]") {
	list<std::shared_ptr<Value>> testList;

	shared_ptr<Value> sPtr1 = std::make_shared<Value>();
	shared_ptr<Value> sPtr2 = std::make_shared<Value>("b", "b", "b", 1, 1, 1);
	testList.push_back(sPtr1);
	testList.push_back(sPtr2);

	printList(testList);

	REQUIRE((*testList.back()).str1_ == "b");

	testList.pop_front();

	printList(testList);

	REQUIRE((*testList.front()).str1_ == "b");

	shared_ptr<Value> sPtr3 = std::make_shared<Value>("c", "c", "c", 2, 2, 2);
	shared_ptr<Value> sPtr4 = std::make_shared<Value>("d", "d", "d", 3, 3, 3);
	testList.push_back(sPtr3);
	testList.push_back(sPtr4);

	printList(testList);

	REQUIRE((*testList.back()).str1_ == "d");

	testList.pop_back();

	REQUIRE((*testList.back()).str1_ == "c");


	shared_ptr<Value> searchPtr = sPtr3;
	auto iter = find(testList.begin(), testList.end(), searchPtr);
	REQUIRE((*(*iter)).str1_ == "c");

	searchPtr = sPtr4;
	iter = find(testList.begin(), testList.end(), searchPtr);
	REQUIRE(iter == testList.end());


	printList(testList);

	shared_ptr<Value> insertPtr = std::make_shared<Value>("bc", "bc", "bc", 3, 3, 3);

	auto iter2 = std::find_if(testList.begin(), testList.end(),
		[&](shared_ptr<Value> v) {
			return (*v).str1_ > (*insertPtr).str1_;
		});
	testList.insert(iter2, insertPtr);

	REQUIRE((*(*std::prev(iter2))).str1_ == "bc");


	printList(testList);
}