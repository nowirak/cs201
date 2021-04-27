/**
 filename:	RGBImage.hpp
 author:	Nick Wirak (adapted from Dr. Genetti work)
 date:		4/26/2021
 summary:	Class to read in and operate on ppm files formatted in ASCII characters.
			Initialize an object with a ppm file name. Use member function toASCII 
			to print to a file an ASCII art representation.

	toASCII:	Converts ppm file to an ASCII art representation, and prints
				the output to a file ("art.txt").

*/

#ifndef RGBIMAGE_HPP
#define RGBIMAGE_HPP

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ifstream;
using std::ofstream;

class RGBImage {
public:
	RGBImage() : _xres(0), _yres(0), _maxval(0) { cout << "DEFAULT" << endl; }
	RGBImage(string fname);
	~RGBImage() { cout << "DESTRUCTOR" << endl; }
	void toASCII();
private:
	int _xres, _yres, _maxval;
	vector<int> _image;

	void dropComment(string& line);
	void getNextVal(int& val, istringstream& iline, ifstream& fin,
		string& line, const string& infile);
};

#endif // !RGBIMAGE_HPP
