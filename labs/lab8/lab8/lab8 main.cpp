// lab8main.cpp
// Chris Hartman
// 9/17/18
// Main program for Lab 8, CS 201 Fall 2018
//
// based on
//
// lab25_main.cpp
// Glenn G. Chappell
// 5 Feb 2018
//
// For CS 201 Spring 2018
// Main program for 2/5 Lab

#include "lab8.hpp"
// For doInput, compute
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


// Main program
// Input three integers using doInput. Call compute on each, and print
// the results.
int main()
{
    // Introductory output
    cout << "Let's get three integers and do computations with them."
        << endl;
    cout << endl;

    // Input three integers
    cout << "Enter the first integer: ";
    int n1 = doInput();
    cout << "Enter the second integer: ";
    int n2 = doInput();
    cout << "Enter the third integer: ";
    int n3 = doInput();
    cout << endl;

    // Do computations
    cout << "Result of computation with the first integer: "
        << compute(n1) << endl;
    cout << "Result of computation with the second integer: "
        << compute(n2) << endl;
    cout << "Result of computation with the third integer: "
        << compute(n3) << endl;
    cout << endl;

    // Wait for user
    cout << "PRESS ENTER ";
    while (cin.get() != '\n');

    return 0;
}

