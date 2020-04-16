/*
	TspSolver.cpp
	Andrew Ng
	Apr 14, 2020
	source for TspSolver class
*/


#include "TspSolver.h"


void TspSolver::SolveRandomly(const std::string& fileName, unsigned int limit)
{
    cities_.read(fileName);
    std::vector<CityNode> cities = cities_.getList();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(1, cities_.getListSize());

    double bestDist = 1.0e+12;
	unsigned int counter = 0;
    while (true) {
		if (counter >= limit) {
			break;
		}
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
                    break;
                }
            }
        }

        chosen.push_back(cities[start - 1]);

        double newDist = 0;
        for (int i = 1; i < chosen.getListSize() - 1; i++) {
            newDist += chosen.distance(i, i + 1);
        }

        if (bestDist > newDist) {
            bestDist = newDist;
            std::vector<int> newPath;
            for (auto c : chosen.getList()) {
                newPath.push_back(c.getNum());
            }
            route_.setPath(newPath);
        }

		counter++;
    }
	std::cout << "Best distance after " << limit;
	std::cout << " tries: " << bestDist << "\n";
}


void TspSolver::SolveGreedy(const std::string& fileName)
{
    cities_.read(fileName);
    std::vector<CityNode> cities = cities_.getList();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(1, cities_.getListSize());

    CityList chosen;
    int start = distr(gen);
    chosen.push_back(cities[start - 1]);
    std::vector<int> unchosen;
    for (int i = 1; i <= cities.size(); i++) {
        if (i != start)
            unchosen.push_back(i);
    }

    while (!unchosen.empty()) {
        double closest = 1.0e+12;
        unsigned int closestId = 0;
        auto removeIter = unchosen.end();

        unsigned int id = chosen.getList().back().getNum();
        for (auto it = unchosen.begin(); it < unchosen.end(); it++) {
            double newDist = cities_.distance(id, *it);
            if (closest > newDist) {
                closest = newDist;
                closestId = *it;
                removeIter = it;
            }
        }

        chosen.push_back(cities[closestId - 1]);
        unchosen.erase(removeIter);
    }

    chosen.push_back(cities[start - 1]);

    double finalDist = 0;
    for (int i = 1; i < chosen.getListSize() - 1; i++) {
        finalDist += chosen.distance(i, i + 1);
    }

    std::vector<int> newPath;
    for (auto c : chosen.getList()) {
        newPath.push_back(c.getNum());
    }
    route_.setPath(newPath);

    std::cout << "Distance: " << finalDist << "\n";
}


void TspSolver::SolveMyWay(const std::string& fileName)
{
	cities_.read(fileName);
	std::vector<CityNode> cities = cities_.getList();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distr(1, cities_.getListSize());

	CityList chosen;
	int start = distr(gen);
	chosen.push_back(cities[start - 1]);
	chosen.push_back(cities[start - 1]);
	std::vector<int> unchosen;
	for (int i = 1; i <= cities.size(); i++) {
		if (i != start)
			unchosen.push_back(i);
	}

	while (!unchosen.empty()) {
		double closest = 1.0e+12;
		unsigned int closestId = 0;
		auto removeIter = unchosen.end();

		//unsigned int id = chosen.getList().back().getNum();
		for (auto it = unchosen.begin(); it < unchosen.end(); it++) {
			for (auto c : chosen.getList()) {
				unsigned int id = c.getNum();
				double newDist = cities_.distance(id, *it);
				if (closest > newDist) {
					closest = newDist;
					closestId = *it;
					removeIter = it;
				}
			}
		}

		double minDist = 1.0e+12;
		std::vector<CityNode> chosenVec = chosen.getList();
		auto insertIter = chosenVec.end();
		for (auto it = chosenVec.begin(); it < chosenVec.end() - 1; it++) {
			double newDist = 0;
			newDist += cities_.distance(it->getNum(), closestId);
			newDist += cities_.distance((it + 1)->getNum(), closestId);
			newDist -= cities_.distance(it->getNum(), (it + 1)->getNum());
			if (minDist > newDist) {
				minDist = newDist;
				insertIter = it + 1;
			}
		}

		chosenVec.insert(insertIter, cities[closestId - 1]);
		chosen.setList(chosenVec);
		unchosen.erase(removeIter);
	}

	double finalDist = 0;
	for (int i = 1; i < chosen.getListSize() - 1; i++) {
		finalDist += chosen.distance(i, i + 1);
	}

	std::vector<int> newPath;
	for (auto c : chosen.getList()) {
		newPath.push_back(c.getNum());
	}
	route_.setPath(newPath);

	std::cout << "Distance: " << finalDist << "\n";
}