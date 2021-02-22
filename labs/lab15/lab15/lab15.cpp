// lab15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "funcs.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> test{ "69", "69a", "a69", "5.6", "    68", "\t11", "68 69", "0xA" };

	for (auto m : test) {
		printSquare(m);
	}

	return 0;
}

