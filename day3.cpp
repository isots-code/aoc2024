#include "day3.h"

int readAndSolveDay3part1(const std::string& path) {

    // Open the file
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file!" << std::endl;
        return {};
    }

    // Define the regex pattern
    std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::smatch match;

    std::vector<std::pair<int, int>> data;
    std::string line;
    while (std::getline(file, line)) {
        // Search for matches in each line
        while (std::regex_search(line, match, pattern)) {
            // Print the matched values
            data.emplace_back(std::stoi(match[1].str()), std::stoi(match[2].str()));

            // Continue searching in the remaining part of the line
            line = match.suffix().str();
        }
    }

    // Close the file
    file.close();

    int sum = 0;
    for (const auto& [a, b] : data)
        sum += a * b;
    return sum;

}

int readAndSolveDay3part2(const std::string& path) {

    // Open the file
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file!" << std::endl;
        return -1;
    }

    // Define the regex pattern
    std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don\'t\(\))");
    std::smatch match;

    std::vector<std::pair<int, int>> data;
    std::string line;
    bool enabled = true;
    while (std::getline(file, line)) {
        // Search for matches in each line
        while (std::regex_search(line, match, pattern)) {

            if (match[0].str().find("mul") != std::string::npos) {
                // Handle "mul()" pattern
                if (enabled)
                    data.emplace_back(std::stoi(match[1].str()), std::stoi(match[2].str()));
            } else if (match[0].str() == "do()") {
                enabled = true;
            } else if (match[0].str() == "don't()") {
                enabled = false;
            }


            // Continue searching in the remaining part of the line
            line = match.suffix().str();
        }

    }

    // Close the file
    file.close();

    int sum = 0;
    for (const auto& [a, b] : data)
        sum += a * b;
    return sum;

}