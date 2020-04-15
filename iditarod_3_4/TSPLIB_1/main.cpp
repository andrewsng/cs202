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
    std::cout << myList.distance(1, 13509) << "\n";
    std::cout << myList.distance(2, 13508) << "\n";
    std::cout << myList.distance(3, 13507) << "\n";
}