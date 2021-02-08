#include "intio.hpp"

// doInput
// Get an integer from a typed line of text; repeat until successful.
// Does no error checking on cin, so avoid using for file input.
//
// Sample usage:
//   cout << "Type your favorite number: ";
//   int favnum = getInt();
//
int doInput() {
	return getInt();
}


// compute
// Do a computation based on n. Return the result.
//
// Sample usage:
//   int n = 42;
//   int result = compute(n);
//
int compute(int n) {
	return n * n;
}