#include <iostream>

#include "day1.h"

int main(int argc, char** argv) {

	std::cout << "hello aoc!\n";

	auto [firstCol, secondCol] = readDay1Input("inputs/day1.txt");

	std::printf("day1 part 1 solution %d\n", solveDay1part1(firstCol, secondCol));

	std::printf("day1 part 2 solution %d\n", solveDay1part2(firstCol, secondCol));

}