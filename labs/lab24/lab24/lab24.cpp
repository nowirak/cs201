// lab24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <iterator>
using std::begin;
using std::endl;
#include <algorithm>
using std::sort;
using std::reverse;
using std::fill;

int main()
{
    vector<int> dataset{21, 5, 63, 37, 8, 13, 19, 88, 24, 19, 43};

    cout << "original vector:" << endl;
    for (const auto &m : dataset) {
        cout << m << endl;
    }

    cout << endl << "sorted vector:" << endl;
    sort(dataset.begin(), dataset.end());
    for (auto m : dataset) {
        cout << m << endl;
    }

    cout << endl << "reversed vector:" << endl;
    reverse(dataset.begin(), dataset.end());
    for (auto m : dataset) {
        cout << m << endl;
    }

    cout << endl << "filled vector (3,7,222):" << endl;
    fill(dataset.begin()+3, dataset.begin()+7, 222);
    for (auto m : dataset) {
        cout << m << endl;
    }

    return 0;
}

