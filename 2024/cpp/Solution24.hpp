#ifndef SOLUTION_24
#define SOLUTION_24

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution_24 {

public:

    Solution_24(int day, string filePath);

    virtual string partOneSolver(string fileName) { return "Error: Not overriding virtual function!"; }
    virtual string partTwoSolver(string fileName) { return "Error: Not overriding virtual function!"; }

    void testDay();

    const int getDay();
    const string getDayString();

private:
    // Single names for answer, example, and input files
    inline static const string answerFile = "_answer.txt";
    inline static const string exampleFile = "_example.txt";
    inline static const string inputFile = "_input.txt";

    // Stores day of this solution
    const int day;

    // Stores path to files
    const string filePathPrefix;
};

#endif //SOLUTION_24