// Lab015.cpp
// Andrew Ng
// Apr 26, 2020
// Lab15 for cs202


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


int main(int argc, char** argv)
{
    std::vector<int> orig = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> dest(10, 0);

    std::transform(orig.begin(), orig.end(), dest.begin(), 
    [](int i) -> int {
        return i * i;
    });

    std::cout << "<algorithm> : transform\n";
    std::cout << "Original vector:\n";
    for (auto o : orig) {
        std::cout << o << " ";
    }
    std::cout << "\nDestination: integers squared\n";
    for (auto d : dest) {
        std::cout << d << " ";
    }
    std::cout << std::endl;


    std::vector<int> orig2 = { 1, 2, 4, 7, 11, 16, 22, 29, 37, 46 };
    std::vector<int> dest2(10, 0);

    std::adjacent_difference(orig2.begin(), orig2.end(), dest2.begin());

    std::cout << "<numeric> : adjacent_difference\n";
    std::cout << "Original vector:\n";
    for (auto o : orig2) {
        std::cout << o << " ";
    }
    std::cout << "\nDestination: differences of pairs from orig.\n";
    for (auto d : dest2) {
        std::cout << d << " ";
    }
    std::cout << std::endl;

    return 0;
}