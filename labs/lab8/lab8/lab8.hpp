// lab8.hpp
// For CS 201 lab 8, Fall 2018
// 9/17/18
// Chris Hartman
//
// based on
// lab25.h
// Glenn G. Chappell
// 5 Feb 2018
//
// For CS 201 Spring 2018
// Header for 2/5 Lab

#ifndef FILE_LAB8_HPP
#define FILE_LAB8_HPP


// doInput
// Get an integer from a typed line of text; repeat until successful.
// Does no error checking on cin, so avoid using for file input.
//
// Sample usage:
//   cout << "Type your favorite number: ";
//   int favnum = getInt();
//
int doInput();


// compute
// Do a computation based on n. Return the result.
//
// Sample usage:
//   int n = 42;
//   int result = compute(n);
//
int compute(int n);


#endif //#ifndef FILE_LAB8_HPP

