/**
* filename: funcs.hpp
* author:   Nick Wirak
* date:     2/8/2021
* summary:	Function declarations file for names.cpp.
* 
*	InputName: Prompts the user individually to input 10 different names.
* 
*	DoesNameExist: Compares a single name(string) with the entries in a 
*		list of names(strings). At least one match returns TRUE.
*
*	PrintNames: Prints a list of names(or strings), each on its own line.
* 
*	SortNames: Alphabetically sorts a list of names(or strings) using 
*		ASCII codes. Acts on the original list.
*/

#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <string>
#include <vector>

void InputNames(std::vector < std::string>& names);

bool DoesNameExist(const std::string& nameToFind, const
	std::vector<std::string>& names);

void PrintNames(const std::vector<std::string>& names);

void SortNames(std::vector <std::string>& names);

#endif