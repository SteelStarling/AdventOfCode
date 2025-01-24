#ifndef SOLUTION_24
#define SOLUTION_24

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Solution_24 {

public:

    Solution_24::Solution_24(int day, string filePath);

    virtual string partOneSolver(string fileName);
    virtual string partTwoSolver(string fileName);

    int testDay() {
        // Print Header
        cout << "   =============== DAY " << setfill('0') << setw(2) << day << " ===============   " << endl;

        // Get correct answers
        

        // Get answers from Part One
        string exampleOneAnswer = partOneSolver(exampleFile);
        string inputOneAnswer = partOneSolver(inputFile);

        // Get answers from Part Two
        string exampleTwoAnswer = partTwoSolver(exampleFile);
        string inputTwoAnswer = partTwoSolver(inputFile);

        // Print Footer
        cout << "   ============= DAY " << setfill('0') << setw(2) << day << " END =============   " << endl << endl << endl << endl;
    }

    int getDay() { return day; }

private:
    // Single names for example and input files
    static const string exampleFile;
    static const string inputFile;

    // Stores day of this solution
    const int day;

    // Stores path to files
    const string filePathPrefix;
};

#endif //SOLUTION_24