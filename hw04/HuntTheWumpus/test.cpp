#include <iostream>
#include <vector>
#include <random>


int main() {
    int size = 15;
    std::vector<double> dv(size, 1.0);
    
    std::discrete_distribution<int> dist(dv.begin(), dv.end());
    for (auto x : dist.probabilities()) {
        std::cout << x << "\n";
    }
    std::cout << "\n";

	dv[3] = 0.0;
	std::discrete_distribution<int> dist2(dv.begin(), dv.end());
    for (auto x : dist2.probabilities()) {
        std::cout << x << "\n";
    }
}