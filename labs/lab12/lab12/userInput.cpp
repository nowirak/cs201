// lab12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "userInput.hpp"
#include <iostream>

void getUserStrings(std::vector<std::string>& words) {

	do {
		words.resize(words.size() + 1);
		std::cin >> words.back();
	} while (words.back() != "end");

	words.pop_back();

	return;
}