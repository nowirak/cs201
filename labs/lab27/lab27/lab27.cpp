// lab27.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;
#include <random>
using std::mt19937;
using std::uniform_int_distribution;

//clock
#include <stdio.h>
#include <time.h>

int main()
{
    std::cout << "Hello World!\n";
}





#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
…
random_device rd;
mt19937 gen(rd()); // PRNG, unpredictable seed
// Distribution for number from 1 to 100
uniform_int_distribution<int> distrib(1, 100);
for (int i = 0; i < 5; ++i)
{
    int randval = distrib(gen);
    cout << "Value: " << randval << endl;
}












// mersenne_twister_engine::seed example
#include <iostream>
#include <chrono>
#include <random>

int main()
{
    typedef std::chrono::high_resolution_clock myclock;
    myclock::time_point beginning = myclock::now();

    // obtain a seed from a user string:
    std::string str;
    std::cout << "Please, enter a seed: ";
    std::getline(std::cin, str);
    std::seed_seq seed1(str.begin(), str.end());

    // obtain a seed from the timer
    myclock::duration d = myclock::now() - beginning;
    unsigned seed2 = d.count();

    std::mt19937 generator(seed1);   // mt19937 is a standard mersenne_twister_engine
    std::cout << "Your seed produced: " << generator() << std::endl;

    generator.seed(seed2);
    std::cout << "A time seed produced: " << generator() << std::endl;


    return 0;
}