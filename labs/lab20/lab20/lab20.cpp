// lab20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES //to enable constants such as M_PI for pi

#include <iostream>
#include <ios> //for fixed and scientific and left and right
#include <iomanip> //for setprecision() and setw()
#include <cmath>

int main()
{
    int interval = 5;

    for (int i = 0; i <= 180; i += interval) {
        std::cout << std::fixed << std::setw(3) << std::right << std::setprecision(0) << i << " ";
        std::cout << std::fixed << std::setw(11) << std::right << std::setprecision(8) << cos(i / 180. * M_PI) << " ";
        std::cout << std::endl;
    }

    return 0;
}

