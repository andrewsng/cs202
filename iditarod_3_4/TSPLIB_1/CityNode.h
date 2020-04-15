/*
    CityNode.h
    Andrew Ng
    Apr 14, 2020
    header for CityNode class
*/


#ifndef CITYNODE_H
#define CITYNODE_H


#include <iostream>


class CityNode
{
public:

    CityNode()
    {}

    CityNode(int num, double latitude,
        double longitude, double x, double y)
        : number_(num), latitude_(latitude),
          longitude_(longitude), x_(x), y_(y)
    {}

    ~CityNode()
    {}

    unsigned int getNum() const { return number_; }

    double getLat() const { return latitude_; }

    double getLong() const { return longitude_; }

    double getX() const { return x_; }

    double getY() const { return y_; }

private:

    unsigned int number_{ 0 };
    double latitude_{ -1.0 };
    double longitude_{ -1.0 };
    double x_{ -1.0 };
    double y_{ -1.0 };

};

std::ostream& operator<<(std::ostream& os, const CityNode& rhs);

#endif