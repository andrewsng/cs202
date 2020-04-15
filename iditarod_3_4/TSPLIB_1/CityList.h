#ifndef CITYLIST_H
#define CITYLIST_H


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

private:

    std::vector<CityNode> list_;
    
};

#endif