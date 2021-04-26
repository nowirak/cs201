// project-cs201.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/**
Version 3
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
    test.frontAdd("test2 here.");
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
