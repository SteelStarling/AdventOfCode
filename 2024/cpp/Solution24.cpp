#include "Solution24.hpp"

Solution_24::Solution_24(int day, string filePath) : day(day), filePathPrefix(filePath) { /*all items initialized*/ }

int Solution_24::testDay() {
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

int Solution_24::getDay() { return day; }