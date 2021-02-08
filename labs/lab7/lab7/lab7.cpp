
#include "intio.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    cout << "Type the first integer: ";
    int num1 = getInt();
    cout << "Type second integer: ";
    int num2 = getInt();
    cout << "Type third integer: ";
    int num3 = getInt();

    cout << endl << "Output: " << endl;

    int min = 0;
    putInt(num1, min);
    cout << endl;
    putInt(num2, min);
    cout << endl;
    putInt(num3, min);
    cout << endl;

    return 0;
}
