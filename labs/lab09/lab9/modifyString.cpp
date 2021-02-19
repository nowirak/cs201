#include "modifyString.hpp"

int modifyString(int myValue, std::string& myString) {
	myString.append(std::to_string(myValue % 10));
	return myString.size();
}