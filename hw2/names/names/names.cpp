/**
* filename: names.cpp
* author:   Nick Wirak
* date:     2/8/2021
* summary:  write stuff
*/

#include <iostream>
#include <vector>
#include <string>
#include "funcs.hpp"

int main(int argc, char **argv)
{
	std::vector<std::string> names;
	InputNames(names);
	std::cout << std::endl;

	std::string nameToFind ("bob");
	std::cout << "Enter a name to search for in the list: ";
	std::getline(std::cin, nameToFind);

	if (DoesNameExist(nameToFind, names) == true)
		std::cout << "'" << nameToFind << "' was found." << std::endl;
	else
		std::cout << "'" << nameToFind << "' was not found." << std::endl;

	std::cout << std::endl;
	std::cout << "List of names in the order given: " << std::endl << std::endl;
	PrintNames(names);

	std::cout << std::endl  << "Alphabetized list:" << std::endl << std::endl;
	SortNames(names);
	PrintNames(names);

	return 0;
}
