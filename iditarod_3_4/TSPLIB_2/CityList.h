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

    std::vector<CityNode> getList() const { return list_; }

	void setList(const std::vector<CityNode>& list) { list_ = list; }

    unsigned int getListSize() const { return list_.size(); }

    void push_back(const CityNode& node) { list_.push_back(node); }

    void read(const std::string& fileName);

    void printList() const;

    double distance(int first, int second) const;

private:

    std::vector<CityNode> list_;

};

#endif