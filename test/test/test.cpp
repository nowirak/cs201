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



int main()
{
	istringstream iss;
	string test;
	int t;

	//iss.str();
	iss >> t;
	if (!iss) cout << "here" << endl;
	iss.str("54");
	iss.clear();
	iss >> t;
	if (!iss) cout << "there" << endl;
	iss >> t;
	if (!iss) cout << "any" << endl;

	return 0;
}
