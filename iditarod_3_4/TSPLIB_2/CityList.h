/*
    CityList.h
    Andrew Ng
    Apr 14, 2020
    header for CityList class
*/


#ifndef CITYLIST_H
#define CITYLIST_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include "CityNode.h"


class CityList
{
public:

    CityList()
    {}

    ~CityList()
    {}

    unsigned int getListSize() const { return list_.size(); }

    void read(const std::string& fileName);

    void printList() const;

    double distance(int first, int second) const;

private:

    std::vector<CityNode> list_;

};

#endif