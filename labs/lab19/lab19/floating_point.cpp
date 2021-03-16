/**
 * @file     floating_point.cpp
 * @author   Student Name
 * @version  Mar 1, 2019
 * John Quan
 *
 * Useful trigonometric functions.
 */

 // using M_PI for pi
#define _USE_MATH_DEFINES
#include <cmath>

#include <vector>

#include<cstdlib>

std::vector<double> degreesToRadians(int degrees) {

	std::vector<double> radians (degrees);

	// for each degree, fill the vector with its radian
	for (int degree = 0; degree < degrees; ++degree) {
		// TODO: calculate a radian and add it to the vector****************

		radians.at(degree) = degree / 180.0 * M_PI;

		// *****************************************************************
	}
	return radians;
}



