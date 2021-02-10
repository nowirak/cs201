/**
* filename: boxprint.cpp
* author:   Nick Wirak
* date:     2/9/2021
* summary:  start
*/

#include "boxer.hpp"
#include <iostream>
using std::cout;
using std::endl;

void boxprint(const std::string& entry, const int& layers) {
	int cols = entry.size() + 2 + layers * 2;
	
	//print top layers of box
	for (int i = 1; i <= layers; i++) {
		for (int j = 1; j <= cols; j++) {
			cout << "*";
		}
		cout << endl;
	}


	//print 1st of the middle three layers of box
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


	//print 2nd of the middle three layers of box (includes user string)
	for (int i = 1; i <= layers; i++) {
		cout << "*";
	}
	cout << " " << entry << " ";
	for (int i = 1; i <= layers; i++) {
		cout << "*";
	}
	cout << endl;


	//print 3rd of the middle three layers of box
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


	//print bottom layers of the box
	for (int i = 1; i <= layers; i++) {
		for (int j = 1; j <= cols; j++) {
			cout << "*";
		}
		cout << endl;
	}
}