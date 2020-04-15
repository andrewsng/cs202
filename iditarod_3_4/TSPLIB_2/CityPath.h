/*
    CityPath.h
    Andrew Ng
    Apr 14, 2020
    header for CityPath class
*/


#ifndef CITYPATH_H
#define CITYPATH_H


#include <vector>


class CityPath
{
public:

    CityPath()
    {}

    ~CityPath()
    {}

    double distance() const;

    void pushNum(int num) { path_.push_back(num); }

private:

    std::vector<int> path_;

};

#endif