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