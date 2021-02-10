//std_lib_facilites.hpp

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

inline void keep_window_open() {
	string tmp;
	cin.clear();
	cout << "Press ENTER to exit the program." << endl;
	getline(cin, tmp);
}

#endif