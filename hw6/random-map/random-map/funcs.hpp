/**
 filename:	funcs.hpp
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

#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using std::map;
#include <random>
#include <cmath>
#include <cstdlib>
using std::rand;


int RandomBetweenU(int first, int last);


int RandomBetweenN(int first, int last);


int RandomBetween(int first, int last);


void PrintDistribution(const map<int, int>& numbers);


#endif