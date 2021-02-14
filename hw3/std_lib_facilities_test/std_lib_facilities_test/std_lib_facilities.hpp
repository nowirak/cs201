/**
 filename:	std_lib_facilities.hpp
 author:	Nick Wirak
 date:		2/9/2021
 summary:	Inclusions of files for use of the Standard Template Library.
			Also includes a simple function to keep console window open if
			necessary.
*/

#ifndef STD_LIB_FACILITIES
#define STD_LIB_FACILITIES

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
//using namespace std;

inline void keep_window_open() {
	string tmp;
	cin.clear();
	cout << "Press ENTER to exit the program." << endl;
	getline(cin, tmp);
}

#endif