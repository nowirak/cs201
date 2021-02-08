/**
* filename: names.cpp
* author:   Nick Wirak
* date:     1/29/2021
* summary:  write stuff
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void InputNames(std::vector < std::string> & names) {
	for (int i = 0; i < 10; i++) {
		std::string name;
		std::cout << "Please enter a name: ";
		std::getline(std::cin, name);
		names.push_back(name);
	}
}

bool DoesNameExist(const std::string& nameToFind, const
	std::vector<std::string>& names) {
	for (int i = 0; i < names.size(); i++) {
		if (nameToFind == names[i])
			return 1;
	}
	return 0;
}

void PrintNames(const std::vector<std::string>& names) {
	std::cout << "The names are: " << std::endl;
	for (int i = 0; i < names.size(); i++) {
		std::cout << names[i] << std::endl;
	}
}

void CountLetters(const std::vector<std::string>& names) {
	std::cout << "The names are: " << std::endl;
	for (int i = 0; i < names.size(); i++) {
		std::cout << names[i] << std::endl;
	}
}

void sortNames(std::vector <std::string>& names){
	std::string temp;
	int min = -1;
	for (int i = 1; i < names.size(); i++){
		for (int j = i - 1; j > -1; j--) {
			if (names.at(j).size() <= names.at(j+1).size())
				min = j;
			else
				min = j+1;
			for (int k = 0; k < names.at(min).size(); k++) {
				if (names.at(j+1).at(k) < names.at(j).at(k)) {
					temp = names.at(j);
					names.at(j) = names.at(j + 1);
					names.at(j + 1) = temp;
					break;
				}
				if (names.at(j + 1).at(k) > names.at(j).at(k)) {
					min = -2;
					
					break;					
				}
				if (names.at(j + 1).at(k) == names.at(j).at(k) && (k+1) != names.at(min).size()) {
					
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


//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////


int main(int argc, char **argv)
{
	std::vector<std::string> names;
	InputNames(names);
	std::cout << std::endl;

	std::string nameToFind ("bob");
	std::cout << "Enter a name to search for: ";
	std::getline(std::cin, nameToFind);

	if (DoesNameExist(nameToFind, names) == true)
		std::cout << "'" << nameToFind << "' was found." << std::endl;
	else
		std::cout << "'" << nameToFind << "' was not found." << std::endl;

	std::cout << std::endl;
	PrintNames(names);

	std::cout << std::endl  << "Sorted Names:" << std::endl << std::endl;
	sortNames(names);
	PrintNames(names);

	return 0;
}
