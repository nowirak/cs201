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

    int* ptr = (int*) 1000;

    cout << (int) ptr << endl;
    if (!ptr) cout << "not" << endl;
    cout << *ptr << endl;

    return 0;

}
