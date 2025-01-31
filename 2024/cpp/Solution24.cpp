#include "Solution24.hpp"

Solution_24::Solution_24(int day, string filePath) : day(day), filePathPrefix(filePath) { /*all items initialized*/ }

void Solution_24::testDay() {
    cout << "   =============== DAY " << setfill('0') << setw(2) << day << " ===============   " << endl;

    // Get correct answers
    string correctAnswers[4];
    string answerFilePath = filePathPrefix + getDayString() + answerFile;
    ifstream answerFile(answerFilePath);
    int numAnswers = 0;
    for(numAnswers = 0; numAnswers < 4 && getline(answerFile, correctAnswers[numAnswers]); ++numAnswers); // fills array and keeps number of valid locations in it

    cout << numAnswers;

    // Get answers from Part One
    string exampleOneAnswer = partOneSolver(exampleFile);
    string inputOneAnswer = partOneSolver(inputFile);

    // Get answers from Part Two
    string exampleTwoAnswer = partTwoSolver(exampleFile);
    string inputTwoAnswer = partTwoSolver(inputFile);

    // Print Footer
    cout << "   ============= DAY " << setfill('0') << setw(2) << day << " END =============   " << endl << endl << endl << endl;
}

const int Solution_24::getDay() { return day; }
const string Solution_24::getDayString() {
        std::ostringstream ss;
        ss << "day" << std::setw(2) << std::setfill('0') << day;
        return ss.str();
}