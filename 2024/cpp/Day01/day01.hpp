#ifndef DAY01
#define DAY01

#include <string>
#include "Solution24.hpp"

class Day01_24 : private Solution_24 {
    int main();

    Day01_24::Day01_24();
    int getTotalDifference(std::string fileName);

    string partOneSolver(string fileName);
    string partTwoSolver(string fileName);
}

#endif //DAY01