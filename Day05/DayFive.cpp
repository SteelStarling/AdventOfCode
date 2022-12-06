
//
// Created by Taylor Hancock on 12/05/22.
//

#include "DayFive.h"

using namespace DayFive;


void DayFive::test() {
    cout << "------ DAY 05 ------" << endl << endl;

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


void DayFive::solvePartOne(string file) {

    ifstream fin(PATH + file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    vector<string> stackStr; // holds all info about the stack

    // fill stackStr with all stack info
    for(string line; getline(fin, line, '\n'); ) {

        if(line.find('1') != -1) { // stop filling when ints are found
            getline(fin, line, '\n'); // eat last line
            break;
        }

        stackStr.push_back(line);
    }

    vector<vector<int>> commands; // holds all commands

    // fill cmdStr with all command info
    string line;
    for(int i = 0; getline(fin, line, '\n'); i++) {

        // removes alphabet chars, code borrowed from https://stackoverflow.com/a/28492056
        line.erase(remove_if(line.begin(), line.end(), [](char c) { return isalpha(c); } ), line.end());

        // create vector to fill
        vector<int> vec(3);

        // ignore first space
        line = line.substr(1);

        // add converted value of first value
        vec.push_back(stoi(line.substr(0, line.find(' '))));

        line = line.substr(line.find(' ') + 2); // remove spaces

        // add converted value of second value
        vec.push_back(stoi(line.substr(0, line.find(' '))));

        line = line.substr(line.find(' ') + 2); // remove spaces

        // add converted value of third value
        vec.push_back(stoi(line.substr(0, line.find(' '))));

    }





    cout << endl;
}


void DayFive::solvePartTwo(string file) {

}