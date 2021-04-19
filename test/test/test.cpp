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



void main()
{
	
	string test("");
	istringstream iss("");

	iss >> test;

	if (!iss) cout << "shit" << endl;

	return;
}
