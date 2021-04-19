// caesar-cypher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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



	while (true) {
		cout << "Enter an integer as a key and some text to encrypt:" << endl;

		do {
			cout << "   key> ";
			getline(cin, text);
			iss.str(text);
			iss.clear();
			iss >> key;
			if (!iss) {
				cout << "***Error. '" << text << "' is not a valid key. Reenter." << endl;
				continue;
			}
			else break;
		} while (true);

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

		cout << "Encrypted text: " << text << endl;
		
		cout << "Would you like to encrypt more text? Type 'yes' to continue or 'no' to exit." << endl;
		do {
			cout << "   continue?> ";
			getline(cin, text);
			if (!cin) {
				cout << "***Error: trouble reading command. Reenter." << endl;
				continue;
			}
			else if (text != "yes" && text != "no") {
				cout << "***Error: '" << text << "' is an invalid command. Enter 'yes' to continue or 'no' to exit." << endl;
				continue;
			}
			else if (text == "yes") {
				break;
			}
			else return 0;
		} while (true);


	}

}

