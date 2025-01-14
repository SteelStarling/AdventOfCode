#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "day01.hpp"

int main() {
    int diff = getTotalDifference("exampleInput.txt");
    std::cout << diff << std::endl;

    return diff;
}

int getTotalDifference(std::string fileName) {
    // Open file and create lists
    std::ifstream file("\\Inputs\\" + fileName);
    std::vector<int> list1, list2;

    // Read in every line (2 numbers a line)
    int a, b;
    while (file >> a >> b) {
        std::cout << "a: " << a << "   b: " << b << std::endl;
        list1.push_back(a);
        list2.push_back(b);
    }
    file.close();

    // Sort lists
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    // Find differences
    int totDiff = 0;
    for (int i = 0; i < list1.size() && i < list2.size(); i++) {
        totDiff += std::abs(list1.at(i) - list2.at(i));
    }

    // Return total difference
    return totDiff;
}