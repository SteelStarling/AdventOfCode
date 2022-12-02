//
// Created by Taylor Hancock on 12/01/22.
//
#include "DayOne.h"


int DayOne() {
    cout << "---- PART ONE ----" << endl;
    cout << "Example: ";
    solvePartOne("Day01/exampleInput.txt");
    cout << endl << "Input: ";
    solvePartOne("Day01/input.txt");
    cout << "---- PART TWO ----" << endl;
    cout << "Example: ";
    solvePartTwoBetter("Day01/exampleInput.txt");
    cout << endl << "Input: ";
    solvePartTwoBetter("Day01/input.txt");
    return 0;
}


void solvePartOne(string file) {
    int maxVal = 0; // holds max value
    int curTot = 0; // holds current total

    ifstream fin(file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    for(string line; getline(fin, line, '\n'); ) { // loop while valid
        if(line.empty()) { // if newline
            maxVal = ((maxVal < curTot) ? curTot : maxVal); // use the ternary operator, making Dahlem disappointed, but my ternary fan brain happy
            curTot = 0; // reset count
        } else { // if text
            curTot += stoi(line); // convert to int
        }
    }

    cout << maxVal << endl;
}


void solvePartTwo(string file) {

    vector<int> maxVals(NUM_VALS); // holds top NUM_VALS max vals
    int curTot = 0; // holds current total

    ifstream fin(file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    int elfCount = 0;
    for(string line; getline(fin, line, '\n'); ) { // loop while valid
        if(line.empty()) { // if newline

            if(elfCount < NUM_VALS) {
                maxVals.at(elfCount) = curTot;
            }

            if(elfCount == NUM_VALS - 1) {
                sort(maxVals.begin(), maxVals.end(), greater<int>());
            }

            if(elfCount >= NUM_VALS && maxVals.back() < curTot) {
                maxVals.back() = curTot;
                sort(maxVals.begin(), maxVals.end(), greater<int>()); // sort each time (this is inefficent, but at these scales, works fine for this)
            }

            curTot = 0; // reset count

            elfCount++;

        } else { // if text
            curTot += stoi(line); // convert to int
        }
    }

    // check last value
    if(maxVals.back() < curTot) {
        maxVals.back() = curTot;
    }

    // add remaining valeus
    int maxTot = 0;
    for(int val : maxVals) {
        maxTot += val;
    }
    cout << maxTot << endl;
}


// uses priority queues, because it makes more sense than whatever nonsense I decided to try
void solvePartTwoBetter(string file) {
    priority_queue<int, vector<int>, greater<int>> maxVals;

    int curTot = 0; // holds current total

    ifstream fin(file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    for(string line; getline(fin, line, '\n'); ) { // loop while valid
        if(line.empty()) { // if newline
            maxVals.push(curTot);
            if(maxVals.size() > NUM_VALS) {
                maxVals.pop();
            }

            curTot = 0; // reset count
        } else { // if text
            curTot += stoi(line); // convert to int
        }
    }

    // push last value onto queue
    maxVals.push(curTot);
    if(maxVals.size() > NUM_VALS) {
        maxVals.pop();
    }

    // just get sum of queue
    int maxTot = 0;
    for(int i = 0; i < NUM_VALS; i++) {
        maxTot += maxVals.top();
        maxVals.pop();
    }

    cout << maxTot << endl;
}