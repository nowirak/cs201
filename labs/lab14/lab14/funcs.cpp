
#include "funcs.hpp"
#include <iostream>

void printStr(const std::string& input) {
	for (int i = 0; i < input.size(); i=i+1) {
		std::cout << input.substr(0, input.size() - i) << std::endl;
	}

	return;
}
