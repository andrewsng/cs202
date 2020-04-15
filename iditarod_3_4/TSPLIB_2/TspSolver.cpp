#include "TspSolver.h"


void TspSolver::SolveRandomly(const std::string& fileName)
{
    cities_.read(fileName);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(1, cities_.getListSize());

    double bestDist = 1.0e+12;
    CityPath chosen;
    int start = distr(gen);
    chosen.pushNum(start);
    std::vector<int> unchosen;
    for (int i = 1; i < cities_.getListSize(); i++) {
        if (i != start)
            unchosen.push_back(i);
    }

    while (!unchosen.empty()) {
        int pick = distr(gen);
        for (auto it = unchosen.begin(); it < unchosen.end(); it++) {
            if (pick == *it) {
                chosen.pushNum(*it);
                unchosen.erase(it);
            }
        }
    }

    chosen.pushNum(start);
}