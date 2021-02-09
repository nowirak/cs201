/**
* filename: funcs.cpp
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


//This will sort a list of strings from lowest ASCII code to
//highest, and can serve to put a list of names into alphabetical
//order. Blank strings are pushed to the bottom of the list.

//The sort algorithm in general is: from top to bottom, compare each
//entry (other than the first) with those higher than it starting with 
//the next highest. Positions in the list are swapped one by one, rather 
//than in blocks. Comparison of entries with those higher halts the 
//first time it is determined that entries should not be switched.

void SortNames(std::vector <std::string>& names) {
	std::string temp;

	//(below) Used to identify the smallest of two strings, and for
	//early breaking out of the 'check all previous' loop if it is
	//not necessary.
	int min = -1;
	
	for (int i = 1; i < names.size(); i++) {	//loop through the list
		for (int j = i - 1; j > -1; j--) {		//loop through entries higher than current
			
			//begin pairwise comparison of two entries
			//determine which is smaller in size
			if (names.at(j).size() <= names.at(j + 1).size())
				min = j;
			else
				min = j + 1;

			//this block serves to push blank entries to the
			//bottom of the list by moving nonblank entries above
			//blank ones
			if (names.at(j).size() == 0 && names.at(j + 1).size() == 0) {
				break;
			}
			if (names.at(j).size() == 0) {
				temp = names.at(j);
				names.at(j) = names.at(j + 1);
				names.at(j + 1) = temp;
				continue;
			}

			//this block facilitates pairwise comparison of entries,
			//and swaps entries if appropriate.
			for (int k = 0; k < names.at(min).size(); k++) {	//loop through string characters
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

			//this stops further comparison of an entry to those
			//higher after it the first time it cannot be moved
			//higher.
			if (min == -2)
				break;
		}
	}
}