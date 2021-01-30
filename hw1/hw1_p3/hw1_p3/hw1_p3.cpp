/**
* filename: hw1_p3.cpp
* author:   Nick Wirak
* date:     1/29/2021
* summary:  Converts user input from kilometers to miles. Allows for repeated conversions.
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	float n;
	char A = 'y';

	cout << "CONVERSION: kilometers to miles" << endl << endl;

	while (A == 'y') {
		cout << "Enter distance in kilometers: ";	//query user for (km) input for conversion
		cin >> n;

		cout << n << " kilometers = " << n / 1.609 << " miles." << endl << endl;	//conversion step

		//forces user to continue with conversions or not with proper input
		do {
			cout << "Additional conversion? (enter 'y' for yes or 'n' for no): ";
			cin >> A;
		} while (A != 'y' && A != 'n');

		cout << endl;
	}

	return 0;
}

