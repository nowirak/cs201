// arrayptrs.cpp  INCOMPLETE
// Glenn G. Chappell
// 11 Apr 2018
//
// For CS 201 Spring 2018
// Programming with Arrays and Pointers
//
// Modified 11/15/18 Chris Hartman
// Modified 04/06/19 John Quan

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iomanip>
using std::setw;
#include <algorithm>

// printPointerStuff
// Given two pointers to items in a common int array, print
//   (1) the distance from ip1 to ip2, and
//   (2) the value of the array item lying halfway between those pointed
//       to by the two pointers.
// The "middle" is the value of the array item lying halfway between those
// pointed to by the two pointers (or the last element of the first half,
// if the pointers lie at an even distance apart).
void printPointerStuff(int* ip1, int* ip2) {
	cout << "Distance from ip1 to ip2: ";

	// TODO: REQUIRED. Print the distance between two array pointers. *******
	auto dist = abs(ip1 - ip2) + 1;  // DUMMY
	cout << dist << endl;
	// **********************************************************************

	cout << "Item halfway between those pointed to by ip1, ip2: ";

	// TODO: REQUIRED. Print the value at the "middle" of the array. ********
	int* middle = nullptr;    // DUMMY
	middle = std::min(ip1, ip2) + abs(ip1 - ip2) / 2;
	cout << *middle;

	// **********************************************************************

	// TODO: ADDITIONAL. Print the entire array with a newline every 10 *****
	//       elements.  Surround the "middle" int with parentheses.
	//       HINT: save it with parentheses in a string.



	// **********************************************************************
	std::cout << std::endl << std::endl;
}

// Main Program
// Make an array and call printPointerStuff multiple times with pointers
// to items in the array.
int main() {
	// Make an array and stick stuff in it
	const int ARRAY1_SIZE = 100;
	int array1[ARRAY1_SIZE];
	for (int i = 0; i < ARRAY1_SIZE; ++i)
		array1[i] = i + 1;

	// Make some calls involving the above array & pointers
	printPointerStuff(&(array1[2]), &(array1[4]));
	printPointerStuff(&(array1[2]), &(array1[25]));
	printPointerStuff(&(array1[10]), &(array1[90]));
	printPointerStuff(&(array1[5]), &(array1[68]));

	// Quit when user hits Enter
	cout << "Press ENTER to quit ";
	while (cin.get() != '\n')
		;
	cout << endl;
}
