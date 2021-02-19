// intio.hpp
// Chris Hartman
// 14 Sep 2018
// based on original by
// Glenn G. Chappell
// 1 Feb 2018
//
// For CS 201 Fall 2018
// Header for Integer I/O Package

#ifndef FILE_INTIO_HPP_INCLUDED
#define FILE_INTIO_HPP_INCLUDED

// getInt
// Get an integer from a typed line of text; repeat until successful.
// Does no error checking on cin, so avoid using for file input.
//
// Sample usage:
//   cout << "Type your favorite number: ";
//   int favnum = getInt();
//
int getInt();

// putInt
// Print the given integer value to cout. At least minchars characters
// are printed. If the number requires fewer characters, then the output
// is padded with leading blanks.
//
// Sample usage:
//   cout << "Your favorite number: ";
//   putInt(favnum, 10);  // Print favnum, using at least 10 characters
//
void putInt(int value,      // Value to output
    int minchars);  // Minimum number of characters to output

#endif //#ifndef FILE_INTIO_HPP_INCLUDED

