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
	int t;
	cin >> t;

	int* ptr = new int[t];

	delete[] ptr;

	vector<int> tester(t);

	cout << sizeof(size_t);

	return 0;
}
