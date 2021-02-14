/**
 filename:	boxer.hpp
 author:	Nick Wirak
 date:		2/9/2021
 summary:	User can repeatedly create printed boxes with one-line strings surrounded
			by user-defined number of layers of asterisks. Error checking is done to 
			force user to input positive integer as the number of box layers. Program
			allows user to exit when ready by inputting 'e'.
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
	
	///
	///
	cout << "Make A String Inside A Box" << endl << endl;	//program title
	cout << "Type a string to put in the box: ";
	getline(cin, entry);	//initial user string input
	cout << "Type the number of layers for the box (a positive integer): ";
	cin >> layers;	//intial user box layers input for boxprint()
	
	//error checking to force user to enter a positive integer for boxprint()
	while (layers < 1) {
		cout << "***The number must be a positive integer. Try again: ";
		cin >> layers;
	}
	cout << endl;
	boxprint(entry, layers);
	cout << endl;
	///
	///

	while (true) {
		
		//query user for continued exit or further box generation
		cout << "Would you like to make another box or exit? Type 'r' to repeat or 'e' to exit: ";
		cin >> exitRequest;
		while (exitRequest != 'r' && exitRequest != 'e') {
			cout << "***Please enter 'r' to repeat or 'e' to exit: ";	//force correct input for exit decision
			cin >> exitRequest;
		}
		if (exitRequest == 'e')
			break;

		///
		///
		/// additional queries for user input. This block is identical to the block outside
		/// the while() loop. The program was organized this way as a solution to problems 
		/// not understood relating to behaviorally poor interactions between cin and getline().
		cout << endl << "Type a string to put in the box: ";
		cin.ignore();	//needed additionally for unknown reasons for getline() to function after 1st iteration
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
		///
		///
	}

	return 0;
}
