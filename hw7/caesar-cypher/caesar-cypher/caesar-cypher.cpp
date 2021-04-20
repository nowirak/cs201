/**
 filename:	caesar-cypher.cpp
 author:	Nick Wirak
 date:		4/20/2021
 summary:	Program that allows the user to input a string of text and encrypt with a 
			caesar cypher of user determined key value. The program prompts for text
			and key, informs the user of invalid entries, and prints encrypted user 
			text as output. The user is repeatedly given the option for additional 
			text encryptions, and can exit the program on command.

*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;

#include "func.hpp"

int main()
{
	cout << "Caesar Cypher demonstration." << endl;

	int key;
	string text;
	istringstream iss;

	// Main program loop. Termination of this loop ends the program.
	while (true) {
		cout << "Enter an integer as a key and some text to encrypt:" << endl;

		// Collect valid user key.
		do {
			cout << "   key> ";
			getline(cin, text);
			iss.str(text);
			iss.clear();
			iss >> key;
			if (!iss) {
				cout << "***Error. '" << text << "' is not a valid key. Reenter.";
				cout << endl;
				continue;
			}
			else break;
		} while (true);

		// Collect valid user text.
		do {
			cout << "   text> ";
			getline(cin, text);
			if (!cin) {
				cout << "***Error: trouble reading text. Reenter." << endl;
				continue;
			}
			else break;
		} while (true);

		for (int i = 0; i < key; i++) {
			caesarCypher(text);
		}

		//Output encrypted user text.
		cout << "Encrypted text: " << text << endl;
		
		cout << "Would you like to encrypt more text? Type 'yes' to continue or 'no'";
			cout << " to exit." << endl;

		// Collect, read, and response to user program continue or exit commands.
		do {
			cout << "   continue?> ";
			getline(cin, text);
			if (!cin) {
				cout << "***Error: trouble reading command. Reenter." << endl;
				continue;
			}
			else if (text != "yes" && text != "no") {
				cout << "***Error: '" << text << "' is an invalid command. Enter ";
				cout << "'yes' to continue or 'no' to exit." << endl;
				continue;
			}
			else if (text == "yes") {
				break;
			}
			else return 0;
		} while (true);

	}

}
