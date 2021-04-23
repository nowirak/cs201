// project-cs201.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/**
Version 1
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

    cout << test.size() << endl;

    test.print();

    test.backRemove();

    cout << test.size() << endl;

    test.print();

    test.frontRemove();

    cout << test.size() << endl;

    test.print();

    return 0;
}
