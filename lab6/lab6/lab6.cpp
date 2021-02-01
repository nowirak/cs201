//

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void printNum(string Input) {
    cout << "String: '" << Input << "'" << endl;
    cout << "Length of the string is: " << Input.size() << endl << endl;
}

int main()
{
    string One = "tiny";
    string Two = "tinytiny";
    string Three = "tinytinytiny";

    printNum(One);
    printNum(Two);
    printNum(Three);

    return 0;
}
