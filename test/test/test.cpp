//
//

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <sstream>
using std::istringstream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
using std::ofstream;



int main()
{
	
	string line;
	ifstream infile("");

	line = "here.txt";	//file name here

	infile.open(line);
	if (!infile) { cout << "Error opening file." << endl; return 1; }

	while (true) {
		getline(infile, line);
		if (!infile) break;
		cout << line << endl;
	}
	if (infile.eof()) {
		infile.close();
		return 0;
	}
	else { cout << "Error reading file." << endl; return 2; }

}
