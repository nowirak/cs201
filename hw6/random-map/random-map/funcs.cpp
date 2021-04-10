/**
 filename:	funcs.cpp
 author:	Nick Wirak
 date:		4/09/2021
 summary:
	RandomBetweenU:		Input an inclusive range of integers to generate a uniform 
						distribution of integers on the range.

	RandomBetweenN:		Input an inclusive range of integers to generate a normal
						distribution on the range. Real valus are rounded down to
						integers.

	RandomBetween:		Input an inclusive range of integers to generate a uniform 
						distribution of integers on the range. This function uses the
						rand() function.

	PrintDistribution:	Outputs a formatted line of a map element that should contain
						as a key an integer from the range of integers specified by the 
						program, and an associated integer that indicates a number of
						asterisks to print. It can be used to generate a horizontal 
						bar graph.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using std::map;
#include <random>
#include <cmath>
#include <cstdlib>
using std::rand;



int RandomBetweenU(int first, int last) {
	// Seed with a real random value, if available
	std::random_device r;

	// Choose a random number
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(first, last);
	return uniform_dist(e1);
}



int RandomBetweenN(int first, int last) {
	// Seed with a real random value, if available
	std::random_device r;

	// Generate a normal distribution around that mean
	std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
	std::mt19937 e2(seed2);
	std::normal_distribution<> normal_dist((first + last) / 2.0, std::round(abs(first - last) / 6.0));

	return std::round(normal_dist(e2));
}



int RandomBetween(int first, int last) {

	return rand() % (abs(first - last) + 1) + first;
}



void PrintDistribution(const map<int, int>& numbers) {
	for (const auto& p : numbers) {
		std::cout << std::fixed << std::setprecision(1) << std::setw(2)
			<< p.first << ' ' << std::string(p.second, '*') << '\n';
	}

	return;
}