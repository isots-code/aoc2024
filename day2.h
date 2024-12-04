#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::vector<int>> readDay2Input(const std::string& path);

int solveDay2part1(const std::vector<std::vector<int>>& input);

int solveDay2part2(const std::vector<std::vector<int>>& input);

bool checkNormalSafe(const std::vector<int>& data);