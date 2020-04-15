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