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

		//unsigned int svgCounter = 0;
        while (!unchosen.empty()) {
            int pick = distr(gen);
            for (auto it = unchosen.begin(); it < unchosen.end(); it++) {
                if (pick == *it) {
                    chosen.push_back(cities[*it - 1]);
                    unchosen.erase(it);

					/*if (svgCounter % 278 == 0) {
						std::vector<int> newPath;
						for (auto c : chosen.getList()) {
							newPath.push_back(c.getNum());
						}
						route_.setPath(newPath);
						std::string fileName = "fnl4461Random_f"
							+ std::to_string(svgCounter / 278) + ".svg";
						std::cout << svgCounter << "\n";
						std::cout << fileName << "\n";
						outputSVG(fileName, 1000, 1000);
					}
					svgCounter++;*/

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

	//unsigned int svgCounter = 0;
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

		/*if (svgCounter % 278 == 0) {
			std::vector<int> newPath;
			for (auto c : chosen.getList()) {
				newPath.push_back(c.getNum());
			}
			route_.setPath(newPath);
			std::string fileName = "fnl4461Greedy_f"
				+ std::to_string(svgCounter / 278) + ".svg";
			outputSVG(fileName, 1000, 1000);
		}

		svgCounter++;*/
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

	//unsigned int svgCounter = 0;
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

		/*if (svgCounter % 278 == 0) {
			std::vector<int> newPath;
			for (auto c : chosen.getList()) {
				newPath.push_back(c.getNum());
			}
			route_.setPath(newPath);
			std::string fileName = "fnl4461Custom_f"
				+ std::to_string(svgCounter / 278) + ".svg";
			outputSVG(fileName, 1000, 1000);
		}

		svgCounter++;*/
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


void TspSolver::outputSVG(const std::string& fileName, 
	unsigned int width, unsigned int height)
{
	std::ofstream fout(fileName);
	if (!fout) {
		std::cout << "ERROR: File could not be output to\n";
	}

	fout << "<svg version=\"1.1\"\n";
	fout << "     baseProfile=\"full\"\n";
	fout << "     width=\"" << width << "\" height=\"" << height << "\"\n";
	fout << "     xmlns=\"http://www.w3.org/2000/svg\">\n";

	std::vector<CityNode> cities = cities_.getList();
	std::vector<int> route = route_.getPath();
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

	fout << "<rect width=\"100%\" height=\"100%\" fill=\"darkslategray\" />";

	for (auto c : cities) {
		int cx = width * 0.9 * (1 - (c.getX() - xmin) / dx);
		int cy = height * 0.9 * (1 - (c.getY() - ymin) / dy);

		fout << "  <circle cx=\"" << cx + width * 0.05 << "\"";
		fout << " cy=\"" << cy + height * 0.05 << "\"";
		fout << " r=\"1.75\" fill=\"beige\" />\n";
	}

	for (size_t i = 0; i < route.size() - 1; i++) {
		int id1 = route[i] - 1;
		int id2 = route[i + 1] - 1;
		int x1 = width * 0.9 * (1 - (cities[id1].getX() - xmin) / dx);
		int y1 = height * 0.9 * (1 - (cities[id1].getY() - ymin) / dy);
		int x2 = width * 0.9 * (1 - (cities[id2].getX() - xmin) / dx);
		int y2 = height * 0.9 * (1 - (cities[id2].getY() - ymin) / dy);

		fout << "  <line x1=\"" << x1 + width * 0.05 << "\"";
		fout << " x2=\"" << x2 + width * 0.05 << "\"";
		fout << " y1=\"" << y1 + height * 0.05 << "\"";
		fout << " y2=\"" << y2 + height * 0.05 << "\"";
		fout << "  stroke=\"beige\" stroke-width=\"1\" stroke-linecap=\"butt\"/>\n";
	}

	fout << "</svg>";
}


void TspSolver::outputPoints(unsigned int width, unsigned int height,
	unsigned int windowX, unsigned int windowY, std::vector<float>& points)
{
	std::vector<CityNode> cities = cities_.getList();
	std::vector<int> route = route_.getPath();
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
	std::vector<CityNode> cities = cities_.getList();
	std::vector<int> route = route_.getPath();
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