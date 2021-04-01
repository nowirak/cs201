// lab25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <utility>
using std::pair;
#include <iterator>
using std::begin;
using std::end;
#include <algorithm>
using std::mismatch;

int main()
{
    vector<int> v1{ 10,11,12,13,14,15,16,17,18,19 };
    vector<int> v2{ 20,21,22,23,24,25,26,27,28,29 };

    auto p = mismatch(v1.begin(), v1.end(), v1.begin());

    if (p.first == v1.end()) {
        cout << "#1: Found no mismatch in matching vectors." << endl;
    }
    else {
        cout << "#1: Found mismatch in matching vectors: ( " << *p.first << " , " << *p.second << " )." << endl;
    }

    p = mismatch(v1.begin(), v1.end(), v2.begin());

    if (p.first == v1.end()) {
        cout << "#2: Found no mismatch in mismatching vectors." << endl;
    }
    else {
        cout << "#2: Found mismatch in mismatching vectors: ( " << *p.first << " , " << *p.second << " )." << endl;
    }

    return 0;
}

