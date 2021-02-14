/**
 filename:	boxprint.cpp
 author:	Nick Wirak
 date:		2/9/2021
 summary:	Function takes a string and positive integer. Prints a box of asterisks
			around the string. The box of asterisks has the number to layers entered
			as the positive integer. The sting is also padded on all sides by a layer
			of spaces. Example:

			call: boxprint("example", 3)

			output:

			***************
			***************
			***************
			***         ***
			*** example ***
			***         ***
			***************
			***************
			***************
*/

#include "boxer.hpp"
#include <iostream>
using std::cout;
using std::endl;

void boxprint(const std::string& entry, const int& layers) {
	int cols = entry.size() + 2 + layers * 2;
	
	//print top layers of box (all asterisks)
	for (int i = 1; i <= layers; i++) {
		for (int j = 1; j <= cols; j++) {
			cout << "*";
		}
		cout << endl;
	}


	//print 1st of the middle three layers of box (asterisk layers and spaces)
	for (int i = 1; i <= layers; i++) {
		cout << "*";
	}
	for (int i = 1; i <= entry.size() + 2; i++) {
		cout << " ";
	}
	for (int i = 1; i <= layers; i++) {
		cout << "*";
	}
	cout << endl;


	//print 2nd of the middle three layers of box (includes user string and asterisks and spaces)
	for (int i = 1; i <= layers; i++) {
		cout << "*";
	}
	cout << " " << entry << " ";
	for (int i = 1; i <= layers; i++) {
		cout << "*";
	}
	cout << endl;


	//print 3rd of the middle three layers of box (asterisk layers and spaces)
	for (int i = 1; i <= layers; i++) {
		cout << "*";
	}
	for (int i = 1; i <= entry.size() + 2; i++) {
		cout << " ";
	}
	for (int i = 1; i <= layers; i++) {
		cout << "*";
	}
	cout << endl;


	//print bottom layers of the box (all asterisks)
	for (int i = 1; i <= layers; i++) {
		for (int j = 1; j <= cols; j++) {
			cout << "*";
		}
		cout << endl;
	}
}