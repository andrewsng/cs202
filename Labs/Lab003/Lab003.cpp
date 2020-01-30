#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <iostream>
#include <memory>
#include "Jumpsuit.h"


using std::cout;
using std::endl;


class Vector3f
{
public:
	Vector3f() : x(0.0), y(0.0), z(0.0)
	{};

	Vector3f(float newX, float newY, float newZ) : x(newX), y(newY), z(newZ)
	{};

	Vector3f(const Vector3f& orig) : x(orig.x), y(orig.y), z(orig.z)
	{};

	float x;
	float y;
	float z;
};


bool operator==(const Vector3f& a, const Vector3f& b) {
	return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}


bool operator!=(const Vector3f& a, const Vector3f& b) {
	return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
}


TEST_CASE( "Vectors are tested", "[Vector3f]" ) {
	Vector3f test1;
	Vector3f test2(3.0, 5.0, 7.0);
	Vector3f test3(test2);

	REQUIRE(test1.x == 0.0);
	REQUIRE(test1.y == 0.0);
	REQUIRE(test1.z == 0.0);

	REQUIRE(test2.x == 3.0);
	REQUIRE(test2.y == 5.0);
	REQUIRE(test2.z == 7.0);

	REQUIRE(test3 == test2);

	REQUIRE(test2 != test1);
}








/*int main()
{
	cout << "Creating raw pointer.\n";
	Jumpsuit* jPtr = new Jumpsuit;


	cout << "\nCreating unique_ptr.\n";
	auto uPtr1 = std::make_unique<Jumpsuit>("red");
	
	cout << "\nTransferring ownership to new unique pointer.\n";
	auto uPtr2 = std::move(uPtr1);

	cout << "\nCalling a member function.\n";
	uPtr2->setColor("green");


	cout << "\nCreating shared_ptr.\n";
	auto sPtr1 = std::make_shared<Jumpsuit>("blue");

	cout << "\nCreating another shared_ptr to the same object.\n\n";
	auto sPtr2 = sPtr1;

}
*/