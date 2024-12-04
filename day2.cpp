#include "day2.h"

std::vector<std::vector<int>> readDay2Input(const std::string& path) {

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return { {}, {} };
    }

    std::vector<std::vector<int>> output;
    std::string line;

    while (std::getline(file, line)) { // Read each line from the file
        std::istringstream iss(line);
        std::vector<int> numbers; // Replace double with int if needed
        int num;

        // Extract numbers from the line
        while (iss >> num) {
            numbers.push_back(num);
        }

        output.push_back(std::move(numbers));

    }

    file.close();

    return output;
}

int solveDay2part1(const std::vector<std::vector<int>>& input) {

    int count = 0;
    for (const auto& a : input)
        count += checkNormalSafe(a);

    return count;

}

int solveDay2part2(const std::vector<std::vector<int>>& input) {

    int count = 0;
    for (const auto& a : input) {
        bool safe = checkNormalSafe(a);
        if (!safe) {
            for (int i = 0; i < a.size(); i++) {
                auto copy = a;
                copy.erase(copy.begin() + i);
                if (checkNormalSafe(copy)) {
                    safe = true;
                    break;
                }
            }
        }
        count += safe;
    }

    return count;

}

bool checkNormalSafe(const std::vector<int>& data) {

    bool safe = true;
    if (data.empty())
        return false;
    bool negative = false;
    for (int i = 1; i < data.size(); i++) {
        const auto diff = data[i - 1] - data[i];
        safe &= (std::abs(diff) >= 1 && std::abs(diff) <= 3);
        if (!safe)
            break;
        const auto neg = diff < 0;
        if (i == 1)
            negative = neg;
        if (negative ^ neg) {
            safe = false;
            break;
        }

    }
    return safe;
}