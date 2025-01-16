#ifndef SOLUTION_24
#define SOLUTION_24

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Solution_24 {

public:

    static const string exampleFile;
    static const string inputFile;

    Solution_24::Solution_24(int day, string filePath);

    virtual string partOneSolver(string fileName);
    virtual string partTwoSolver(string fileName);

    int testDay() {
        // Print Header
        cout << "   =============== DAY " << setfill('0') << setw(2) << day << " ===============   " << endl;

        // Get correct answers
        

        // Get answers from Part One
        string exampleOneAnswer = partOneSolver(filePathPrefix + exampleFile);
        string inputOneAnswer = partOneSolver(filePathPrefix + inputFile);

        // Get answers from Part Two
        string exampleTwoAnswer = partTwoSolver(filePathPrefix + exampleFile);
        string inputTwoAnswer = partTwoSolver(filePathPrefix + inputFile);

        // Print Footer
        cout << "   =============== DAY " << setfill('0') << setw(2) << day << " ===============   " << endl;
    }

private:
    const int day;
    const string filePathPrefix; // stores path to files
};

#endif //SOLUTION_24