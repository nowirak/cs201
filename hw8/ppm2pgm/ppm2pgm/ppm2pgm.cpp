/**
 filename:	ppm2pgm.cpp
 author:	Nick Wirak (adapted from Dr. Genetti work)
 date:		4/26/2021
 summary:   This program creates a greyscale ppm image file from a RGB ppm image and
            outputs the representation to a text file named 'pgmImage.txt'. The input
            image file should be titled 'parrot.ppm', and the ppm should be formatted
            in ascii characters (as opposed to a binary representation). The program
            should accomodate ppm files formatted in the usual way, and allow for '#'
            commenting on any line desired.

*/

// EXAMPLE PPM FORMATTING
/* This is the first few lines of parrot.ppm
P3
# CREATOR: GIMP PNM Filter Version 1.1
80 80
255
0
0
1
10
11
8
*/

#include <iostream>
using std::cout;
using std::endl;

#include "RGBImage.hpp"

int main()
{
    cout << "Program to convert a ppm to ascii art." << endl;

    RGBImage ppm("parrot.ppm");
    ppm.writePGMFile("pgmImage.pgm");

    cout << "Program finished." << endl;
}
