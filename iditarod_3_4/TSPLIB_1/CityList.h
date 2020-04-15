#ifndef CITYLIST_H
#define CITYLIST_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "CityNode.h"


class CityList
{
public:

    CityList()
    {}

    ~CityList()
    {}

    void read(std::string fileName);

    void printList() const;

private:

    std::vector<CityNode> list_;

};

#endif