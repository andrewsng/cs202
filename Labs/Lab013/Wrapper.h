// Wrapper.h
// Andrew Ng
// Apr 19, 2020
// header for Wrapper class


#ifndef WRAPPER_H
#define WRAPPER_H


#include <iostream>


template <typename T>
class Wrapper
{
public:

	Wrapper(const T& obj) : object_(obj) {};

	template <typename U>
	friend std::ostream& operator<<(std::ostream& os, const Wrapper<U>& obj);

private:

	T object_;

};

template <typename U>
std::ostream& operator<<(std::ostream& os, const Wrapper<U>& obj)
{
	os << obj.object_;
	return os;
}


#endif