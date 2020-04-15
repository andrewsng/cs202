#include "TspSolver.h"


void TspSolver::SolveRandomly(const std::string& fileName)
{
    cities_.read(fileName);
    std::vector<CityNode> cities = cities_.getList();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(1, cities_.getListSize());

    double bestDist = 1.0e+12;
    while (true) {
        CityList chosen;
        int start = distr(gen);
        chosen.push_back(cities[start - 1]);
        std::vector<int> unchosen;
        for (int i = 1; i <= cities.size(); i++) {
            if (i != start)
                unchosen.push_back(i);
        }

        while (!unchosen.empty()) {
            int pick = distr(gen);
            for (auto it = unchosen.begin(); it < unchosen.end(); it++) {
                if (pick == *it) {
                    chosen.push_back(cities[*it - 1]);
                    unchosen.erase(it);
                    continue;
                }
            }
        }

        chosen.push_back(cities[start - 1]);

        double newDist = 0;
        for (int i = 1; i < chosen.getListSize() - 1; i++) {
            newDist += chosen.distance(i, i + 1);
        }

        std::cout << "Best Distance: " << bestDist << "\n";
        std::cout << "New Distance: " << newDist << "\n";

        if (bestDist > newDist) {
            bestDist = newDist;
            std::vector<int> newPath;
            for (auto c : chosen.getList()) {
                unsigned int id = c.getNum();
                std::cout << id << "\n";
                newPath.push_back(id);
            }
            route_.setPath(newPath);
        }
    }
}