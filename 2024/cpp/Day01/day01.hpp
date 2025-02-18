#ifndef DAY01
#define DAY01

#include <string>
#include "Solution24.hpp"

class Day01_24 : private Solution_24 {

    Day01_24::Day01_24(int day, string filePath);
    int getTotalDifference(std::string fileName);

    string partOneSolver(string fileName);
    string partTwoSolver(string fileName);
};

int main();

#endif //DAY01