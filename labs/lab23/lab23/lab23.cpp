// lab23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;
#include <map>
using std::map;
#include <string>
using std::string;

int main()
{
	map < string, int> data {
		{ "bob", 55 },
		{ "zack", 34 },
		{ "joe", 22 },
		{ "pete", 27 },
		{ "kurt", 44 },
		{ "andy", 42 }
	};

	for (const auto& data : data) {
		cout << "Key: " << data.first << ", value: " << data.second;
		cout << endl;
	}

	data.erase("kurt");

	cout << endl << "after erase:" << endl << endl;

	for (const auto& data : data) {
		cout << "Key: " << data.first << ", value: " << data.second;
		cout << endl;
	}

	return 0;
}

