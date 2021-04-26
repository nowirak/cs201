
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
	RGBImage(string infile);
	~RGBImage() { cout << "DESTRUCTOR" << endl; }
	void toASCII();
	void writePGMFile(string fname);
private:
	int _xres, _yres, _maxval;
	vector<int> _image;

	void dropComment(string& line);
	void getNextVal(int& val, istringstream& iline, ifstream& fin,
		string& line, const string& infile);
};

#endif // !RGBIMAGE_HPP
