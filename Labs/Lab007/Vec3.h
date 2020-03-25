#ifndef VEC3_H
#define VEC3_H


#include <iostream>


class Vec3 {
public:
	Vec3();

	Vec3& operator=(const Vec3& other);

	double getX() const { return x_; };
	double getY() const { return y_; };
	double getZ() const { return z_; };

	void setX(double newX) { x_ = newX; };
	void setY(double newY) { y_ = newY; };
	void setZ(double newZ) { z_ = newZ; };

private:
	double x_{ 1.0 };
	double y_{ 1.0 };
	double z_{ 1.0 };
};


std::ostream& operator<<(std::ostream& os, const Vec3& vec);

#endif