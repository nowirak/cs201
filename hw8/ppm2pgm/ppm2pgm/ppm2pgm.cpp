/**
 filename:	asciiart.cpp
 author:	Nick Wirak (adapted from Dr. Genetti work)
 date:		4/20/2021
 summary:   This program creates an ascii art representation of a RGB ppm image and
            outputs the representation to a text file named 'art.txt'. The image file
            should be titled 'parrot.ppm', and the ppm should be formatted in ascii
            characters (as opposed to a binary representation). The program should
            accomodate ppm files formatted in the usual way, and allow for '#'
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






#if 0
////////////////////////////////////////////////

/**
 filename:	ppm2pgm.cpp
 author:	Nick Wirak (adapted from Dr. Genetti work)
 date:		4/20/2021
 summary:   This program creates a greyscale ppm image file from a RGB ppm image and
            outputs the representation to a text file named 'pgmImage.txt'. The input
            image file should be titled 'parrot.ppm', and the ppm should be formatted
            in ascii characters (as opposed to a binary representation). The program
            should accomodate ppm files formatted in the usual way, and allow for '#'
            commenting on any line desired.

*/

//EXAMPLE PPM FORMATTING
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
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <algorithm>
#include <iterator>
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;

//Checks a string for the '#' symbol which signifies commets in ppm files.
//Removes the comment from the line.
inline void dropComment(string& line) {
    std::string::iterator itr(std::find(line.begin(), line.end(), '#'));
    if (itr != line.end()) {
        cout << "Ignoring comment." << endl;
        line.resize(itr - line.begin(), ' ');
    }
}

//Retrieves next integer value from file. Checks for failure to read from file.
//Intregrally drops comments as part of its operation.
inline void getNextVal(int& val, istringstream& iline, ifstream& fin,
    string& line, const string& infile) {
    while (true) {
        iline >> val;
        if (!iline) {
            getline(fin, line);
            if (!fin) {
                cout << "Error reading " << infile << "." << endl;
                exit(2);
            }
            dropComment(line);
            iline.str(line);
            iline.clear();
            continue;
        }
        else break;
    }
}

int main()
{
    cout << "Program to convert a ppm to a pgm." << endl;

    // open the file
    string infile = "parrot.ppm";
    ifstream fin(infile);
    if (!fin) {
        cout << "Error opening " << infile << "." << endl;
        exit(1);
    }
    cout << "Opened " << infile << endl;

    // read the magic number
    string line;
    getline(fin, line);
    if (!fin) {
        cout << "Error reading " << infile << "." << endl;
        exit(2);
    }
    dropComment(line);
    if (line.size() < 2 || line[0] != 'P' || line[1] != '3') {
        cout << "Unable to read magic number P3." << endl;
        exit(3);
    }
    else {
        cout << "PPM (text)" << endl;
    }

    string outfile = "pgmImage.txt";
    ofstream fout(outfile);
    if (!fout) cout << "Error creating " << outfile << endl;
    fout << "P2" << endl;

    // get file parameters (x-resolution, y-resolution, max-value)
    istringstream iline(' ');
    int xres, yres, maxval;
    getNextVal(xres, iline, fin, line, infile);
    getNextVal(yres, iline, fin, line, infile);
    getNextVal(maxval, iline, fin, line, infile);
    cout << "Image size: " << xres << " x " << yres << endl;
    cout << "Maxval = " << maxval << endl;

    const int grayScaleVals = 32;   // set to a divisor of 256
    const int grayDivisor = 256 / grayScaleVals;
    fout << xres << " " << yres << endl << grayScaleVals << endl;

    // Loop for xres*yres pixels. Converts RGB -> Grey -> Ascii.
    int r, g, b, iy;
    double y;
    vector<string> values(grayScaleVals);
    for (int i = 0; i < grayScaleVals; i++) {
        values.at(i) = std::to_string(i);
    }
    for (int i = 0; i < xres * yres; i++) {
        getNextVal(r, iline, fin, line, infile);
        getNextVal(g, iline, fin, line, infile);
        getNextVal(b, iline, fin, line, infile);
        // Y = 0.2126R + 0.7152G + 0.0722B (from HW7)
        y = 0.2126 * r + 0.7152 * g + 0.0722 * b;
        // test
        if (y < 0.0 || y >= 256.0) cout << "ERROR!!!!!!!!!!!" << endl;
        //    cout << r << " " << g << " " << b;
        //    cout << " => " << y;
        iy = (int)y;
        // iy should be [0...255]
        if (iy < 0 || iy > 255) cout << "ERROR!!!!!!!!!!!!!!" << endl;
        //    cout << " => " << iy;
        iy /= grayDivisor;
        // iy should be [0...15]
        if (iy < 0 || iy >= grayScaleVals) cout << "ERROR!!!!!!!!!!!!!!" << endl;
        //    cout << " => " << iy << endl;


        fout << values[iy] << " ";
        if (!fout) cout << "Error writing to " << outfile << endl;
        if (i % 35 == 34) fout << endl;
        if (!fout) cout << "Error writing to " << outfile << endl;
    }

    cout << "Conversion finished." << endl;
}
#endif