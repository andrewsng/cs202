#ifndef TSPSOLVER_H
#define TSPSOLVER_H


#include "CityList.h"
#include "CityPath.h"


class TspSolver
{
public:

    TspSolver()
    {}

    ~TspSolver()
    {}

private:

    CityList cities_;
    CityPath route_;

};

#endif