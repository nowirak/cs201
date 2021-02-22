
#include "funcs.hpp"
#include <sstream>
#include <iostream>

bool printSquare(const string& input) {
	istringstream istream (input);
	int num;
	
	istream >> num;

	if (!istream) {
		cout << "***Error. No number entered." << endl;
		return 0;
	}
	else {
		cout << "The square is: " << num*num << endl;
		return 1;
	}
}