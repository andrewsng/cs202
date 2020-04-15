/*
    main.cpp
    Andrew Ng
    Apr 14, 2020
    main for TSPLIB part 1
*/


#include <iostream>
#include "CityList.h"


int main()
{
    CityList myList;
    myList.read("usa13509.tsp");
    myList.printList();
}