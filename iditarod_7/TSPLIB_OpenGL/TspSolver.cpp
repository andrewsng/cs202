/*
	TspSolver.cpp
	Andrew Ng
	Apr 14, 2020
	source for TspSolver class
*/


#include "TspSolver.h"


void TspSolver::randomInit(const std::string& fileName)
{
    cities_.read(fileName);
    cities = cities_.getList();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(1, cities_.getListSize());

    start = distr(gen);
    chosen.push_back(cities[start - 1]);
    for (int i = 1; i <= cities.size(); i++) {
        if (i != start)
            unchosen.push_back(i);
    }

	std::vector<int> newPath;
	for (auto c : chosen.getList()) {
		newPath.push_back(c.getNum());
	}
	route_.setPath(newPath);
}


void TspSolver::randomStep()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distr(1, cities_.getListSize());

	if (!unchosen.empty()) {
		int pick = distr(gen);
		for (auto it = unchosen.begin(); it < unchosen.end(); it++) {
			if (pick == *it) {
				chosen.push_back(cities[*it - 1]);
				unchosen.erase(it);

				break;
			}
		}
	}
	else if (!solved_) {
		chosen.push_back(cities[start - 1]);

		double finalDist = 0;
		for (int i = 1; i < chosen.getListSize() - 1; i++) {
			finalDist += chosen.distance(i, i + 1);
		}

		std::cout << "Distance: " << finalDist << "\n";

		solved_ = true;
	}

	std::vector<int> newPath;
	for (auto c : chosen.getList()) {
		newPath.push_back(c.getNum());
	}
	route_.setPath(newPath);
}


void TspSolver::greedyInit(const std::string& fileName)
{
    cities_.read(fileName);
    cities = cities_.getList();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(1, cities_.getListSize());

    start = distr(gen);
    chosen.push_back(cities[start - 1]);
    for (int i = 1; i <= cities.size(); i++) {
        if (i != start)
            unchosen.push_back(i);
    }

	std::vector<int> newPath;
	for (auto c : chosen.getList()) {
		newPath.push_back(c.getNum());
	}
	route_.setPath(newPath);
}


void TspSolver::greedyStep()
{
	if (!unchosen.empty()) {
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
	else if (!solved_) {
		chosen.push_back(cities[start - 1]);

		double finalDist = 0;
		for (int i = 1; i < chosen.getListSize() - 1; i++) {
			finalDist += chosen.distance(i, i + 1);
		}

		std::cout << "Distance: " << finalDist << "\n";

		solved_ = true;
	}

	std::vector<int> newPath;
	for (auto c : chosen.getList()) {
		newPath.push_back(c.getNum());
	}
	route_.setPath(newPath);
}


void TspSolver::customInit(const std::string& fileName)
{
	cities_.read(fileName);
	cities = cities_.getList();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distr(1, cities_.getListSize());

	start = distr(gen);
	chosen.push_back(cities[start - 1]);
	chosen.push_back(cities[start - 1]);
	for (int i = 1; i <= cities.size(); i++) {
		if (i != start)
			unchosen.push_back(i);
	}

	std::vector<int> newPath;
	for (auto c : chosen.getList()) {
		newPath.push_back(c.getNum());
	}
	route_.setPath(newPath);
}


void TspSolver::customStep()
{
	if (!unchosen.empty()) {
		double closest = 1.0e+12;
		unsigned int closestId = 0;
		auto removeIter = unchosen.end();

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
	else if (!solved_) {
		double finalDist = 0;

		for (int i = 1; i < chosen.getListSize() - 1; i++) {
			finalDist += chosen.distance(i, i + 1);
		}

		std::cout << "Distance: " << finalDist << "\n";

		solved_ = true;
	}

	std::vector<int> newPath;
	for (auto c : chosen.getList()) {
		newPath.push_back(c.getNum());
	}
	route_.setPath(newPath);
}


void TspSolver::outputPoints(unsigned int width, unsigned int height,
	unsigned int windowX, unsigned int windowY, std::vector<float>& points)
{
	double xmin = cities[0].getX();
	double xmax = cities[0].getX();
	double ymin = cities[0].getY();
	double ymax = cities[0].getY();
	for (int i = 0; i < cities.size(); i++) {
		xmin = std::min(xmin, cities[i].getX());
		xmax = std::max(xmax, cities[i].getX());
		ymin = std::min(ymin, cities[i].getY());
		ymax = std::max(ymax, cities[i].getY());
	}

	double dx = xmax - xmin;
	double dy = ymax - ymin;
	double padX = (windowX - width) / 2;
	double padY = (windowY - height) / 2;

	for (size_t i = 0; i < cities.size(); i++) {
		int cx = width * (1 - (cities[i].getX() - xmin) / dx);
		int cy = height * ((cities[i].getY() - ymin) / dy);

		points.push_back(cx + padX);
		points.push_back(cy + padY);
	}
}


void TspSolver::outputLines(unsigned int width, unsigned int height,
	unsigned int windowX, unsigned int windowY, std::vector<float>& lines)
{
	std::vector<int> route = route_.getPath();

	if (route.size() < 2) {
		return;
	}

	double xmin = cities[0].getX();
	double xmax = cities[0].getX();
	double ymin = cities[0].getY();
	double ymax = cities[0].getY();
	for (int i = 0; i < cities.size(); i++) {
		xmin = std::min(xmin, cities[i].getX());
		xmax = std::max(xmax, cities[i].getX());
		ymin = std::min(ymin, cities[i].getY());
		ymax = std::max(ymax, cities[i].getY());
	}

	double dx = xmax - xmin;
	double dy = ymax - ymin;
	double padX = (windowX - width) / 2;
	double padY = (windowY - height) / 2;

	for (size_t i = 0; i < route.size() - 1; i++) {
		int id1 = route[i] - 1;
		int id2 = route[i + 1] - 1;
		int x1 = width * (1 - (cities[id1].getX() - xmin) / dx);
		int y1 = height * ((cities[id1].getY() - ymin) / dy);
		int x2 = width * (1 - (cities[id2].getX() - xmin) / dx);
		int y2 = height * ((cities[id2].getY() - ymin) / dy);

		lines.push_back(x1 + padX);
		lines.push_back(y1 + padY);
		lines.push_back(x2 + padX);
		lines.push_back(y2 + padY);
	}
}