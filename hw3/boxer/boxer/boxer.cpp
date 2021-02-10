/**
* filename: boxer.cpp
* author:   Nick Wirak
* date:     2/9/2021
* summary:  start
*/

#include <iostream>
#include <string>
#include "boxer.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	string entry = "";
	int layers = 0;
	char exitRequest = 'r';
	
	cout << "Make A String Inside A Box" << endl << endl;
	cout << "Type a string to put in the box: ";
	getline(cin, entry);
	cout << "Type the number of layers for the box (a positive integer): ";
	cin >> layers;
	while (layers < 1) {
		cout << "***The number must be a positive integer. Try again: ";
		cin >> layers;
	}
	cout << endl;
	boxprint(entry, layers);
	cout << endl;

	while (true) {
		
		cout << "Would you like to make another box or exit? Type 'r' to repeat or 'e' to exit: ";
		cin >> exitRequest;
		while (exitRequest != 'r' && exitRequest != 'e') {
			cout << "***Please enter 'r' to repeat or 'e' to exit: ";
			cin >> exitRequest;
		}
		if (exitRequest == 'e')
			break;

		cout << endl << "Type a string to put in the box: ";
		cin.ignore();
		getline(cin, entry);
		cout << "Type the number of layers for the box (a positive integer): ";
		cin >> layers;
		while (layers < 1) {
			cout << "***The number must be a positive integer. Try again: ";
			cin >> layers;
		}
		cout << endl;
		boxprint(entry, layers);
		cout << endl;
	}

	return 0;
}

