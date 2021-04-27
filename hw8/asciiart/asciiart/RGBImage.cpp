/**
 filename:	RGBImage.cpp
 author:	Nick Wirak (adapted from Dr. Genetti work)
 date:		4/26/2021
 summary:
    toASCII:	Converts ppm file to an ASCII art representation, and prints
                the output to a file ("art.txt").
    dropComment:Drops any comment found in a line of a ppm file formatted in
                ASCII characters.
    getNextVal: Gets the next integer value of a ppm file formatted in ASCII 
                characters.

*/

#include <string>
using std::string;
#include <fstream>
using std::ifstream;
using std::ofstream;

#include "RGBImage.hpp"

// Checks a string for the '#' symbol which signifies commets in ppm files.
// Removes the comment from the line.
void RGBImage::dropComment(string& line) {
    std::string::iterator itr(std::find(line.begin(), line.end(), '#'));
    if (itr != line.end()) {
        cout << "Ignoring comment." << endl;
        line.resize(itr - line.begin(), ' ');   //note: resizing may be less efficient
        //than inserting spaces?
    }
}

// Retrieves next integer value from file. Checks for failure to read from file.
// Intregrally drops comments as part of its operation.
void RGBImage::getNextVal(int& val, istringstream& iline, ifstream& fin,
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

RGBImage::RGBImage(string infile):_xres(0),_yres(0),_maxval(0),_image(0) {

    // open the file
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

    // get file parameters (x-resolution, y-resolution, max-value)
    istringstream iline(' ');
    getNextVal(_xres, iline, fin, line, infile);
    getNextVal(_yres, iline, fin, line, infile);
    getNextVal(_maxval, iline, fin, line, infile);
    cout << "Image size: " << _xres << " x " << _yres << endl;
    cout << "Maxval = " << _maxval << endl;

    int r, g, b;
    for (int i = 0; i < _xres * _yres; i++) {
        getNextVal(r, iline, fin, line, infile);
        _image.push_back(r);
        getNextVal(g, iline, fin, line, infile);
        _image.push_back(g);
        getNextVal(b, iline, fin, line, infile);
        _image.push_back(b);
    }
    if (_image.size() != _xres * _yres * 3) {
        cout << "File may be corrupted." << endl;
    }
}

void RGBImage::toASCII() {
    string outfile = "art.txt";
    ofstream fout(outfile);
    if (!fout) cout << "Error creating " << outfile << endl;

    int iy;
    double y;
    char values[] = "@%%##ss*+==--:: ";    // " ::--==+*ss##%%@"
    for (int i = 0; i < _image.size(); i+=3) {
        // Y = 0.2126R + 0.7152G + 0.0722B (from HW7)
        y = 0.2126 * _image.at(i) + 0.7152 * _image.at(i+1) + 0.0722 * _image.at(i+2);
        // test
        if (y < 0.0 || y >= 256.0) cout << "ERROR!!!!!!!!!!!" << endl;
        //    cout << r << " " << g << " " << b;
        //    cout << " => " << y;
        iy = (int)y;
        // iy should be [0...255]
        if (iy < 0 || iy > 255) cout << "ERROR!!!!!!!!!!!!!!" << endl;
        //    cout << " => " << iy;
        iy /= 16;
        // iy should be [0...15]
        if (iy < 0 || iy > 15) cout << "ERROR!!!!!!!!!!!!!!" << endl;
        //    cout << " => " << iy << endl;


        fout << values[iy] << " ";
        if (!fout) cout << "Error writing to " << outfile << endl;
        if (i/3 % 80 == 79) fout << endl;
        if (!fout) cout << "Error writing to " << outfile << endl;
    }
}