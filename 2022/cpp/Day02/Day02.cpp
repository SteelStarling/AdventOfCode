
//
// Created by Taylor Hancock on 12/02/22.
//

#include "Day02.h"
using namespace Day02;


void Day02::test() {
    cout << "------ DAY 02 ------" << endl << endl;

    cout << "---- PART ONE ----" << endl;
    cout << "Example: ";
    solvePartOne("exampleInput.txt");
    cout << endl << "Input: ";
    solvePartOne("input.txt");
    cout << "---- PART TWO ----" << endl;
    cout << "Example: ";
    solvePartTwo("exampleInput.txt");
    cout << endl << "Input: ";
    solvePartTwo("input.txt");
}


void Day02::solvePartOne(string file) {

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


void Day02::solvePartTwo(string file) {

    ifstream fin(PATH + file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    int score = 0;
    for(string line; getline(fin, line, '\n'); ) {

        // convert chars to ints
        int their = line.at(0) - 65;
        char state = line.at(2);

        if(state == 'Z') { // check for wins
            score += ((their + 1) % 3) + 1; // increase score by value
            score += 6;
        } else if(state == 'Y') { // check for ties
            score += their + 1;
            score += 3;
        } else { // must be loss
            score += ((their + 2) % 3) + 1;
        }
    }

    cout << score << endl;
}