
//
// Created by Taylor Hancock on 12/05/22.
//

#include "DayFive.h"

using namespace DayFive;


void DayFive::test() {
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


void DayFive::solvePartOne(string file) {

    ifstream fin(PATH + file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    vector<vector<char>> stackChars; // holds all info about the stack

    // fill stackStr with all stack info
    for(string line; getline(fin, line, '\n'); ) {

        if(line.find('1') != -1) { // stop filling when ints are found
            getline(fin, line, '\n'); // eat last line
            break;
        }

        vector<char> stackRow;

        // iterate through each char and add to list
        for(int i = 1; i < line.length(); i += 4) {
            stackRow.push_back(line.at(i)); // isolate char
        }

        stackChars.push_back(stackRow);
    }

    vector<stack<char>> stackVec;

    // fill stackVec with the actual stacks
    if(!stackChars.empty()) {
        for(int i = 0; i < stackChars.at(0).size(); i++) {

            stack<char> st;
            for(int j = stackChars.size() - 1; j >= 0; j--) { // count backwards as stacks feed backwards

                if(stackChars.at(j).at(i) != ' ') { // only add if not a space
                    st.push(stackChars.at(j).at(i));
                }

            }

            stackVec.push_back(st); // add stack to vector
        }
    } else {
        cout << "ERROR: stackChars is empty! Stopping program!" << endl;
        return;
    }

    vector<vector<int>> commands; // holds all commands

    // fill cmdStr with all command info
    for(string line; getline(fin, line, '\n'); ) {

        // removes alphabet chars, code borrowed from https://stackoverflow.com/a/28492056
        line.erase(remove_if(line.begin(), line.end(), [](char c) { return isalpha(c); } ), line.end());

        // create vector to fill
        vector<int> vec;

        // ignore first space
        line = line.substr(1);

        // add converted value of first value
        vec.push_back(stoi(line.substr(0, line.find(' '))));

        line = line.substr(line.find(' ') + 2); // remove spaces

        // add converted value of second value
        vec.push_back(stoi(line.substr(0, line.find(' '))));

        line = line.substr(line.find(' ') + 2); // remove spaces

        // add converted value of third value
        vec.push_back(stoi(line));

        // add vector to commands
        commands.push_back(vec);
    }

    // handle each command
    for(vector<int> command : commands) {
        // perform task the right number of times
        for(int i = 0; i < command.at(0); i++) {
            // ensure not empty
            if(!stackVec.at(command.at(1) - 1).empty()) {
                // get top
                char c = stackVec.at(command.at(1) - 1).top();
                stackVec.at(command.at(1) - 1).pop();

                // move top to new stack
                stackVec.at(command.at(2) - 1).push(c);
            }
        }
    }

    // get top of each
    for(stack<char> s : stackVec) {
        cout << s.top();
    }
}


void DayFive::solvePartTwo(string file) {
    ifstream fin(PATH + file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    vector<vector<char>> stackChars; // holds all info about the stack

    // fill stackStr with all stack info
    for(string line; getline(fin, line, '\n'); ) {

        if(line.find('1') != -1) { // stop filling when ints are found
            getline(fin, line, '\n'); // eat last line
            break;
        }

        vector<char> stackRow;

        // iterate through each char and add to list
        for(int i = 1; i < line.length(); i += 4) {
            stackRow.push_back(line.at(i)); // isolate char
        }

        stackChars.push_back(stackRow);
    }

    vector<stack<char>> stackVec;

    // fill stackVec with the actual stacks
    if(!stackChars.empty()) {
        for(int i = 0; i < stackChars.at(0).size(); i++) {

            stack<char> st;
            for(int j = stackChars.size() - 1; j >= 0; j--) { // count backwards as stacks feed backwards

                if(stackChars.at(j).at(i) != ' ') { // only add if not a space
                    st.push(stackChars.at(j).at(i));
                }

            }

            stackVec.push_back(st); // add stack to vector
        }
    } else {
        cout << "ERROR: stackChars is empty! Stopping program!" << endl;
        return;
    }

    vector<vector<int>> commands; // holds all commands

    // fill cmdStr with all command info
    for(string line; getline(fin, line, '\n'); ) {

        // removes alphabet chars, code borrowed from https://stackoverflow.com/a/28492056
        line.erase(remove_if(line.begin(), line.end(), [](char c) { return isalpha(c); } ), line.end());

        // create vector to fill
        vector<int> vec;

        // ignore first space
        line = line.substr(1);

        // add converted value of first value
        vec.push_back(stoi(line.substr(0, line.find(' '))));

        line = line.substr(line.find(' ') + 2); // remove spaces

        // add converted value of second value
        vec.push_back(stoi(line.substr(0, line.find(' '))));

        line = line.substr(line.find(' ') + 2); // remove spaces

        // add converted value of third value
        vec.push_back(stoi(line));

        // add vector to commands
        commands.push_back(vec);
    }

    // handle each command
    for(vector<int> command : commands) {
        vector<char> store;

        // perform task the right number of times
        for(int i = 0; i < command.at(0); i++) {
            // ensure not empty
            if(!stackVec.at(command.at(1) - 1).empty()) {
                // get top
                char c = stackVec.at(command.at(1) - 1).top();
                stackVec.at(command.at(1) - 1).pop();

                // add to list
                store.push_back(c);
            }
        }

        // fill stack with
        for(int i = 0; i < command.at(0); i++) {
            stackVec.at(command.at(2) - 1).push(store.back());
            store.pop_back();
        }
    }

    // get top of each
    for(stack<char> s : stackVec) {
        cout << s.top();
    }
}