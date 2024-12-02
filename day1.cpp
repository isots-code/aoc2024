#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>


#include "day1.h"

std::pair<std::vector<int>, std::vector<int>> readDay1Input(const std::string& path) {

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return { {}, {} };
    }

    std::vector<int> firstColumn, secondColumn;
    int num1, num2;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (iss >> num1 >> num2) {
            firstColumn.push_back(num1);
            secondColumn.push_back(num2);
        }
    }

    file.close();

    return { firstColumn, secondColumn };
}

int solveDay1part1(std::vector<int> firstColumn, std::vector<int> secondColumn) {
    if (firstColumn.size() != secondColumn.size()) {
        std::cerr << "Different lenght vectors!" << std::endl;
        return -1;
    }
    std::sort(begin(firstColumn), end(firstColumn));
    std::sort(begin(secondColumn), end(secondColumn));

    int res = 0;
    for (size_t i = 0; i < firstColumn.size(); i++) {
        res += std::abs(firstColumn[i] - secondColumn[i]);
    }

    return res;
}

int solveDay1part2(std::vector<int> firstColumn, std::vector<int> secondColumn) {
    if (firstColumn.size() != secondColumn.size()) {
        std::cerr << "Different lenght vectors!" << std::endl;
        return -1;
    }
    std::unordered_multiset<int> set;
    for (const auto& ele : secondColumn)
        set.insert(ele);

    int res = 0;
    for (const auto& ele : firstColumn) {
        auto a = set.count(ele);
        res += ele * a;
    }

    return res;
}