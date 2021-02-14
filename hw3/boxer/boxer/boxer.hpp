/**
 filename:	boxer.hpp
 author:	Nick Wirak
 date:		2/9/2021
 summary:	boxprint(), "boxprint.cpp"
				Function takes a string and positive integer. Prints a box of asterisks
				around the string.
*/

#ifndef BOXER_HPP
#define BOXER_HPP

#include <string>

void boxprint(const std::string& entry, const int& layers);

#endif