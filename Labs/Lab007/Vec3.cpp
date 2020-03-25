#include "Vec3.h"


Vec3::Vec3()
{}


Vec3& Vec3::operator=(const Vec3& other)
{
	x_ = other.getX();
	y_ = other.getY();
	z_ = other.getZ();

	return *this;
}


std::ostream& operator<<(std::ostream& os, const Vec3& vec)
{
	os << "<"  << vec.getX();
	os << ", " << vec.getY();
	os << ", " << vec.getZ();
	os << ">";

	return os;
}