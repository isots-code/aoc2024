#include <iostream>

#include "day1.h"
#include "day2.h"
#include "day3.h"

int main(int argc, char** argv) {

	std::cout << "hello aoc!\n";

	//auto [firstCol, secondCol] = readDay1Input("inputs/day1.txt");
	//std::printf("day1 part 1 solution %d\n", solveDay1part1(firstCol, secondCol));
	//std::printf("day1 part 2 solution %d\n", solveDay1part2(firstCol, secondCol));

	//const auto data = readDay2Input("inputs/day2.txt");
	//std::printf("day2 part 1 solution %d\n", solveDay2part1(data));
	//std::printf("day2 part 2 solution %d\n", solveDay2part2(data));

	std::printf("day3 part 1 solution %d\n", readAndSolveDay3part1("inputs/day3.txt"));
	std::printf("day3 part 1 solution %d\n", readAndSolveDay3part2("inputs/day3.txt"));


}