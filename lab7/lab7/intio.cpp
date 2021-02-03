// intio.cpp
// Chris Hartman
// 14 Sep 2018
// based on original by
// Glenn G. Chappell
// 1 Feb 2018
//
// For CS 201 Fall 2018
// Source for Integer I/O Package

#include "intio.hpp"  // Header for this package
#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
using std::ostringstream;
#include <cstdlib>
using std::size_t;


// getInt
// See header file for doc's.
int getInt()
{
    int num;
    while (true)
    {
        // Input a line of text
        string line;
        getline(cin, line);

        // Get an integer from the line, if possible.
        // Return it on success; otherwise, print a message, and repeat.
        istringstream instr(line);
        instr >> num;
        if (!instr)
        {
            cout << "*** Try again; type an integer: ";
        }
        else
        {
            return num;
        }
    }
}


// putInt
// See header file for doc's.
void putInt(int value,     // Value to output
    int minchars)  // Minimum number of characters to output
{
    // Get the string form of the number
    // [Yes, I know about std::to_string; I also know that some recent
    // versions of Visual C++ do not support it correctly. :-( ]
    ostringstream outstr;
    outstr << value;
    string result = outstr.str();

    // Left-pad with blanks
    if (result.size() < size_t(minchars))
    {
        cout << string(size_t(minchars) - result.size(), ' ');
    }
    cout << result;
}

