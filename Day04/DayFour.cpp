
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

// no error checking because here it's not needed, could cause issues if actually attempted
void DayFour::solvePartOne(string file) {

    ifstream fin(PATH + file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    int count = 0;
    for(string line; getline(fin, line, '\n'); ) {
        string first, last;
        int splitPos = line.find(',');

        // split across comma
        first = line.substr(0, splitPos);
        last = line.substr(splitPos + 1);

        // get first vals
        splitPos = first.find('-');
        int firstMin = stoi(first.substr(0, splitPos));
        splitPos = first.find('-');
        int firstMax = stoi(first.substr(splitPos + 1));

        // get last vals
        splitPos = last.find('-');
        int lastMin = stoi(last.substr(0, splitPos));
        splitPos = last.find('-');
        int lastMax = stoi(last.substr(splitPos + 1));

        // check if one contains the other
        if((firstMin <= lastMin && firstMax >= lastMax) || (firstMin >= lastMin && firstMax <= lastMax)) {
            count++;
        }
    }

    cout << count << endl;
}

void DayFour::solvePartTwo(string file) {

    ifstream fin(PATH + file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    int count = 0;
    for(string line; getline(fin, line, '\n'); ) {
        string first, last;
        int splitPos = line.find(',');

        // split across comma
        first = line.substr(0, splitPos);
        last = line.substr(splitPos + 1);

        // get first vals
        splitPos = first.find('-');
        int firstMin = stoi(first.substr(0, splitPos));
        splitPos = first.find('-');
        int firstMax = stoi(first.substr(splitPos + 1));

        // get last vals
        splitPos = last.find('-');
        int lastMin = stoi(last.substr(0, splitPos));
        splitPos = last.find('-');
        int lastMax = stoi(last.substr(splitPos + 1));

        // check if one contains the other
        if(!((firstMax < lastMin) || (firstMin > lastMax))) {
            count++;
        }
    }

    cout << count << endl;
}