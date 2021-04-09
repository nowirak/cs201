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
	string user;
	getline(cin, user);
	istringstream iss(user);

	int quant;

	iss >> quant;

	if (!iss) {
		cout << "no" << endl;
	}
	else {
		cout << quant << endl;
	}

	
	iss.clear();

	iss >> quant;

	if (!iss) {
		cout << "no" << endl;
	}
	else {
		cout << quant << endl;
	}

	return 0;
}
