/**
* filename: hw1_p1.cpp
* author:   Nick Wirak
* date:     1/29/2021
* summary:  Queries user for a positive integer. Prints a diamond pattern using that integer.
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int n;

	cout << "Enter a positive integer: ";
	cin >> n;
	cout << endl;

	//error check w/ program break
	if (n < 1) {
		cout << "You did not enter a positive integer." << endl;
		return 1;
	}

	//prints the first n rows of the diamond
	for (int i = 1; i <= n; i++) {
		for (int j = n-i; j > 0; j--) {
			cout << " ";
		}
		
		for (int k = 1; k <= 2*i-1; k++) {
			cout << "#";
		}

		cout << endl;
	}
	
	//prints remaining n-1 rows of the diamond
	for (int i = 1; i <= n - 1; i++ ) {
		for (int j = 1; j <= i; j++) {
			cout << " ";
		}

		for (int k = 2*(n-i)-1; k > 0; k--) {
			cout << "#";
		}

		cout << endl;
	}

	return 0;
}
