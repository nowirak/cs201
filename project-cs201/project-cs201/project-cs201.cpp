/**
 filename:	project-cs201.cpp
 author:	Nick Wirak (adapted from Dr. Genetti work)
 date:		4/27/2021
 summary:   This program is intended as a simple test of the accompanying LinkedList
            class. Not all the member functions are tested within, but the code can
            be adjusted to test according to interest.

*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "LinkedList.hpp"

int main()
{
    LinkedList test;

    test.frontAdd("test1 here.");
    test.backAdd("test2 here.");
    test.frontAdd("test3 here.");
    test.frontAdd("test4 here.");

    cout << "Size: " << test.size() << endl;
    cout << "Items:" << endl;
    test.print();
    cout << endl;

    test.backRemove();

    cout << "Size: " << test.size() << endl;
    cout << "Items:" << endl;
    test.print();
    cout << endl;

    test.frontRemove();

    cout << "Size: " << test.size() << endl;
    cout << "Items:" << endl;
    test.print();
    cout << endl;

    return 0;
}
