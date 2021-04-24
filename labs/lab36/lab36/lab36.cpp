// lab36.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;

unsigned int flagA = 1;
unsigned int flagB = 2;
unsigned int flagC = 4;

void idFlags(unsigned int flag) {
    if ((flag & flagA) != 0) {
        cout << "flagA set" << endl;
    }
    if ((flag & flagB) != 0) {
        cout << "flagB set" << endl;
    }
    if ((flag & flagC) != 0) {
        cout << "flagC set" << endl;
    }
}

int main()
{
    unsigned int test1 = flagA;
    unsigned int test2 = flagA | flagB;
    unsigned int test3 = flagB | flagC;
    unsigned int test4 = flagA | flagB | flagC;

    idFlags(test1);
    cout << endl;
    idFlags(test2);
    cout << endl;
    idFlags(test3);
    cout << endl;
    idFlags(test4);
    cout << endl;

}
