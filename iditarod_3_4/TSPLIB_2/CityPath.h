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

    void setPath(const std::vector<int>& path) { path_ = path; }

private:

    std::vector<int> path_;

};

#endif