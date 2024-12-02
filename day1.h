#pragma once

#include <string>
#include <vector>
#include <utility>

std::pair<std::vector<int>, std::vector<int>> readDay1Input(const std::string& path);

int solveDay1part1(std::vector<int> firstColumn, std::vector<int> secondColumn);

int solveDay1part2(std::vector<int> firstColumn, std::vector<int> secondColumn);