
//
// Created by Taylor Hancock on 12/05/22.
//

#include "DayFour.h"

using namespace DayFour;


void DayFour::test() {
    cout << "------ DAY 04 ------" << endl << endl;

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


void DayFour::solvePartOne(string file) {

    ifstream fin(PATH + file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    int count = 0;
    for(string line; getline(fin, line, '\n'); ) {

    }
}