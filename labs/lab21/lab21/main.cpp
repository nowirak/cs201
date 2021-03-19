// lab21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
#include "truncstruct.hpp"

int main()
{
    cout << "Enter a string: ";

    string input;
    getline(cin, input);

    cout << endl << "You entered \"" << input << "\"." << endl;

    cout << endl << "Result: " << trunc8(input).str << endl;

    return 0;
}

