/**
 * @file     floating_point.hpp
 * @author   Student Name
 * @version  Mar 1, 2019
 * John Quan
 *
 * Useful trigonometric functions.
 */

#ifndef FLOATING_POINT_HPP_
#define FLOATING_POINT_HPP_

#include <vector>

 /**
  * Return a vector of radians where the angle in degrees equates
  * to the index, and the element at that index holds the equivalent
  * angle in radians. Therefore,  DEGREE == INDEX
  * For example:
  *    vector<double> radians = degreesToRadians(2);
  * Contains:  INDEX     RADIAN
  *            0         0
  *            1         0.0174533
  *            2         0.0349066
  *
  * @param degrees from 0 to this value
  * @return Vector of radians
  */
std::vector<double> degreesToRadians(int degree);

#endif /* FLOATING_POINT_HPP_ */
