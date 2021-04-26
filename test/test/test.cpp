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

    string test("this");
    string* ptr = &test;
    cout << ptr << endl;
    test = "thieh siejfapidj aipejf iaoej fajweio jaioe fjapoj fioajo jaeo fjaopweja";
    cout << ptr << endl;

    return 0;
}
