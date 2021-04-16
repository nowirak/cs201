// what is our algorithm?
// This will be wordy while writing/debugging
// Agile - get it working for parrot.ppm

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

inline void dropComment(string &line) {
    std::string::iterator itr (std::find(line.begin(), line.end(), '#'));
    if (itr != line.end()) {
        cout << "Ignoring comment." << endl;
        line.resize(itr - line.begin(), ' ');
    }
}

inline void getNextVal(int &val, istringstream& iline, ifstream &fin, string &line, const string& infile) {
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
    cout << "Program to convert a ppm to ascii art." << endl;

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
    if (line.size() < 2 || line[0] != 'P' || line [1] != '3') {
        cout << "Unable to read magic number P3." << endl;
        exit(3);
    }
    else {
        cout << "PPM (text)" << endl;
    }

    // get file parameters
    istringstream iline (' ');
    int xres, yres, maxval;
    getNextVal(xres, iline, fin, line, infile);
    getNextVal(yres, iline, fin, line, infile);
    getNextVal(maxval, iline, fin, line, infile);
    cout << "Image size: " << xres << " x " << yres << endl;
    cout << "Maxval = " << maxval << endl;

    string outfile = "art.txt";
    ofstream fout(outfile);
    if (!fout) cout << "Error creating " << outfile << endl;

    // loop for xres*yres
    int r, g, b, iy;
    double y;
    char values[] = "@%%##ss*+==--:: ";    // " ::--==+*ss##%%@"
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
        iy /= 16;
        // iy should be [0...15]
        if (iy < 0 || iy > 15) cout << "ERROR!!!!!!!!!!!!!!" << endl;
        //    cout << " => " << iy << endl;


        fout << values[iy] << " ";
        if (!fout) cout << "Error writing to " << outfile << endl;
        if (i % 80 == 79) fout << endl;
        if (!fout) cout << "Error writing to " << outfile << endl;
    }

    cout << "Program finished." << endl;
}
