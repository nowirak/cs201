#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;
//using namespace std;

int main()
{
	string user;

	while (true) {
		cout << "Enter a string (just 'ENTER' to quit): ";
		std::getline(cin, user);
		if (user.size() == 0)
			break;
		else {
			cout << "Lower case letters: ";
			for (int i = 0; i < user.size(); i++) {
				if (user.at(i) >= 97 && user.at(i) <= 122)
					cout << user.at(i);
			}
		}
		cout << endl << endl;
	}

	return 0;
}

