
//
// Created by Taylor Hancock on 12/02/22.
//

#include "DayTwo.h"
using namespace DayTwo;


void DayTwo::test() {
    cout << "------ DAY 02 ------" << endl << endl;

    cout << "---- PART ONE ----" << endl;
    cout << "Example: ";
    solvePartOne("exampleInput.txt");
    cout << endl << "Input: ";
    solvePartOne("input.txt");
}


void DayTwo::solvePartOne(string file) {

    ifstream fin(PATH + file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    int score = 0;
    for(string line; getline(fin, line, '\n'); ) {

        // convert chars to ints
        int their = line.at(0) - 65;
        int your = line.at(2) - 88;

        score += your + 1; // increase score by value

        if((your + 2) % 3 == their) { // check for wins
            score += 6;
        } else if(your == their) { // check for ties
            score += 3;
        } // must be loss
    }

    cout << score << endl;
}


void DayTwo::solvePartTwo(string file);