/**
* filename: lab3.cpp
* author:   Nick Wirak
* date:     1/27/2021
* summary:  Print numbers 1-100. If divisible by 3, print 'Fizz' instead of number.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	for (int i = 1; i < 101; i++) {
		if (i % 3 != 0)
			cout << i << endl;
		else
			cout << "Fizz" << endl;
	}

	cout << endl;
	cout << "Type ENTER to continue: ";
	while (cin.get() != '\n');
	cout << endl;

	for (int i = 1; i < 101; i++) {
		if (i % 3 == 0) {
			cout << "Fizz";
			if (i % 5 == 0)
				cout << " Buzz";
			cout << endl;
		}
		else if (i % 5 == 0)
			cout << "Buzz" << endl;
		else
			cout << i << endl;
	}

	return 0;
}
