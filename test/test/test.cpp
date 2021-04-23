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

    int in;
    cin >> in;
    int* ptr = new int [in];

    delete[] ptr;

    return 0;
}
