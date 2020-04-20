// Wrapper.h
// Andrew Ng
// Apr 19, 2020
// header for Wrapper class


#ifndef WRAPPER_H
#define WRAPPER_H


template <typename T>
class Wrapper
{
public:

	Wrapper(const T& obj) : object_(obj) {};

private:

	T object_;

};

#endif