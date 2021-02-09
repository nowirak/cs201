/**
* filename: funcs.hpp
* author:   Nick Wirak
* date:     2/8/2021
* summary:  write stuff
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