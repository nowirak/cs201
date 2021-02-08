/**
* filename: lab5.cpp
* author:   Nick Wirak
* date:     1/29/2021
* summary:  does almost nothing
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int n;

	cout << "Enter an integer: ";
	cin >> n;
	cout << endl;

	switch (n)
	{
	case 3:
		cout << "You entered 3.";
		break;
	case 4:
		cout << "You entered 4.";
		break;
	default:
		cout << "You didn't enter 3 or 4.";
		break;
	}

	cout << endl << endl;

	return 0;

}
