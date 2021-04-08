// shopping.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <map>
using std::map;
#include <string>;
using std::string;

struct Record {
    double unitPrice;
    int units;
};

int main()
{
    map<string, Record> store
    { {"toothbrush", {0.50, 60}},
        {"book", {6.00, 30}},
        {"covid mask", {0.25, 1000}},
        {"paper cup", {0.10, 1000}},
        {"light bulb", {1.00, 100}} };


    map<string, Record> cart;

    cout << 

    return 0;
}

