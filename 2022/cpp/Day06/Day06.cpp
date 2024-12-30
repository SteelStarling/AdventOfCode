
//
// Created by Taylor Hancock on 12/09/22.
//

#include "Day06.h"
using namespace Day06;


void Day06::test() {
    cout << "------ DAY 05 ------" << endl;

    cout << endl << "---- PART ONE ----" << endl;
    cout << "Example: ";
    solvePartOne("exampleInput.txt");
    cout << endl << "Input: ";
    solvePartOne("input.txt");
    cout << endl << "---- PART TWO ----" << endl;
    cout << "Example: ";
    solvePartTwo("exampleInput.txt");
    cout << endl << "Input: ";
    solvePartTwo("input.txt");
}


void Day06::solvePartOne(string file) {

    ifstream fin(PATH + file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    deque<char> lastFour;

    string line;
    getline(fin, line, '\n');

    if(line.length() < 4) { // stop before this breaks things
        cout << "ERROR: Line is not long enough!";
        return;
    }

    // fill with initial values
    for(int i = 0; i < line.length(); i++) {
        lastFour.push_back(line.at(i));

        // clear front values each time
        if(lastFour.size() > 4) {
            lastFour.pop_front();

            char c0 = lastFour.at(0), c1 = lastFour.at(1), c2 = lastFour.at(2), c3 = lastFour.at(3);

            // ensure no repeats (obviously better ways to handle this, but this works fine)
            if(c0 != c1 && c0 != c2 && c0 != c3 && c1 != c2 && c1 != c3 && c2 != c3) {
                // print if no repeats (i + 1 because 0 indexed)
                cout << (i + 1);
                return;
            }
        }
    }

    cout << "Not Found!";
}


// the one time I don't design part one to be easily expandable...Advent of Code is why I always do stuff programmatically
void Day06::solvePartTwo(string file) {

    const int maxSize = 14;

    ifstream fin(PATH + file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    deque<char> last;

    string line;
    getline(fin, line, '\n');

    if(line.length() < maxSize) { // stop before this breaks things
        cout << "ERROR: Line is not long enough!";
        return;
    }

    // fill with initial values
    vector<int> letters(26);
    for(int i = 0; i < line.length(); i++) {
        char c = line.at(i);
        last.push_back(c);
        letters.at(c - 97)++; // keep track of numbers

        // clear front values each time
        if(last.size() > maxSize) {
            letters.at(last.front() - 97)--; // keep track of numbers
            last.pop_front();

            bool found = false;
            for(int num : letters) {
                if(num > 1) {
                    found = true;
                }
            }

            // if greater than 2 was never encountered, must be the marker
            if(!found) {
                cout << (i + 1);
                return;
            }
        }
    }

    cout << "No marker found!";
}