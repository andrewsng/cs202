#include "Vec3.h"


Vec3::Vec3()
{}


std::ostream& operator<<(std::ostream& os, const Vec3& vec)
{
	os << "<"  << vec.getX();
	os << ", " << vec.getY();
	os << ", " << vec.getZ();
	os << ">";

	return os;
}