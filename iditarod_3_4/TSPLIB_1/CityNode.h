#ifndef CITYNODE_H
#define CITYNODE_H


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

private:

    unsigned int number_{ 0 };
    double latitude_{ -1.0 };
    double longitude_{ -1.0 };
    double x_{ -1.0 };
    double y_{ -1.0 };
    
};

#endif