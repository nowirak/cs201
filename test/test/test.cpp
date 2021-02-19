//
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{

    std::string stringvalues = "125 320 512 750 333";
    getline(cin, stringvalues);
    std::istringstream iss (stringvalues);

    string val;
    iss >> val;

    cout << bool (iss >> val);

    for (int i = 1; i < 6; i++) {
        cout << val << endl;
        iss >> val;
    }

    return 0;
}
