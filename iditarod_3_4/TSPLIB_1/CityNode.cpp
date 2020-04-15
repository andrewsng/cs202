/*
    CityNode.cpp
    Andrew Ng
    Apr 14, 2020
    source for CityNode class
*/


#include "CityNode.h"


std::ostream& operator<<(std::ostream& os, const CityNode& rhs)
{
    os << rhs.getNum() << " ";
    os << rhs.getLat() << " ";
    os << rhs.getLong() << " ";
    os << rhs.getX() << " ";
    os << rhs.getY();
    return os;
}