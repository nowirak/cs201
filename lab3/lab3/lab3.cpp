/**
* filename: lab3.cpp
* author:   Nick Wirak
* date:     1/25/2021
* summary:  Prints integers 1-20 sequentially and creates a printed 60x10 array of asterisks.
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    int i, j;

    i = 1;
    while(i<=20)
    {
        cout << i << endl;
        i++;
    }

    cout << endl;
    cout << "Type ENTER to continue: ";
    while (cin.get() != '\n');
    cout << endl;
    
    i = j = 1;
    while(i<=6)
    {
        while (j <= 10)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        j = 1;
        i++;
    }

    return 0;
}