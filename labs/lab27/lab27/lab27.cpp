// lab27.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;
#include <random>
using std::mt19937;
using std::uniform_int_distribution;
using std::random_device;

//clock
#include <stdio.h>
#include <time.h>

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(0, 1);

    int heads = 0;
    int tails = 0;
   
	for (int i = 0; i < 1000; i++) {
		if (distrib(gen) == 1) {
			heads++;
			continue;
		}
		tails++;
	}
	cout << "Results are: " << heads << " heads, and " << tails << " tails." << endl;

    return 0;
}

