//
//

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	string a = "";

	for (int i = 0; i < 5; i++) {
		cout << "Enter: ";
		getline(cin, a);
		cout << a << endl;
	}

	return 0;
}

