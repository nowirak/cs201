/**
* filename: funcs.cpp
* author:   Nick Wirak
* date:     2/8/2021
* summary:  write stuff
*/

#include "funcs.hpp"
#include <iostream>
#include <algorithm>

void InputNames(std::vector < std::string>& names) {
	for (int i = 0; i < 10; i++) {
		std::string name;
		std::cout << "Please enter a name: ";
		std::getline(std::cin, name);
		names.push_back(name);
	}
}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////


bool DoesNameExist(const std::string& nameToFind, const
	std::vector<std::string>& names) {
	for (int i = 0; i < names.size(); i++) {
		if (nameToFind == names[i])
			return 1;
	}
	return 0;
}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////


void PrintNames(const std::vector<std::string>& names) {
	for (int i = 0; i < names.size(); i++) {
		std::cout << names[i] << std::endl;
	}
}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////


void SortNames(std::vector <std::string>& names) {
	std::string temp;
	int min = -1;
	for (int i = 1; i < names.size(); i++) {
		for (int j = i - 1; j > -1; j--) {
			if (names.at(j).size() <= names.at(j + 1).size())
				min = j;
			else
				min = j + 1;
			if (names.at(j).size() == 0 && names.at(j + 1).size() == 0) {
				break;
			}
			if (names.at(j).size() == 0) {
				temp = names.at(j);
				names.at(j) = names.at(j + 1);
				names.at(j + 1) = temp;
				continue;
			}
			for (int k = 0; k < names.at(min).size(); k++) {
				if (names.at(j + 1).at(k) < names.at(j).at(k)) {
					temp = names.at(j);
					names.at(j) = names.at(j + 1);
					names.at(j + 1) = temp;
					break;
				}
				if (names.at(j + 1).at(k) > names.at(j).at(k)) {
					min = -2;
					break;
				}
				if (names.at(j + 1).at(k) == names.at(j).at(k) && (k + 1) != names.at(min).size()) {
					continue;
				}
				if (min == j + 1) {
					temp = names.at(j);
					names.at(j) = names.at(j + 1);
					names.at(j + 1) = temp;
					break;
				}
				min = -2;
				break;
			}
			if (min == -2)
				break;
		}
	}
}