/*
    CityList.cpp
    Andrew Ng
    Apr 14, 2020
    source for CityList class
*/


#include "CityList.h"


bool checkIfstream(const std::ifstream& fin)
{
    if (!fin) {
        if (fin.eof()) {
            std::cout << "ERROR: end of file\n";
            return 0;
        }
        std::cout << "ERROR: file could not be read\n";
        return 0;
    }
    return 1;
}


void CityList::read(std::string fileName)
{
    std::ifstream fin(fileName);
    if (!fin) {
        std::cout << "ERROR: file could not be opened\n";
        return;
    }
    std::string label;
    while (true) {
        std::getline(fin, label);
        if (!checkIfstream(fin))
            return;

        if (label == "NODE_COORD_SECTION")
            break;
    }

    while (true) {
        if (!checkIfstream(fin))
            break;

        int num;
        double latitude;
        double longitude;

        fin >> num;
        if (!checkIfstream(fin))
            break;
        
        fin >> latitude;
        if (!checkIfstream(fin))
            break;

        fin >> longitude;
        if (!checkIfstream(fin))
            break;

        list_.push_back(CityNode(num, latitude, longitude, longitude, latitude));
    }
}


void CityList::printList() const
{
    for (auto n : list_) {
        std::cout << n << "\n";
    }
}


double CityList::distance(int first, int second) const
{
    if (first == second ||
        first < 1 || 
        second < 1 ||
        first > list_.size() ||
        second > list_.size()) 
        return 0;
    return sqrt(pow(list_[second - 1].getX() - list_[first - 1].getX(), 2) +
                pow(list_[second - 1].getY() - list_[first - 1].getY(), 2));
}