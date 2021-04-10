// lab28.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;

int main()
{
    ofstream fout("testThis.txt");
    if (!fout) {
        cout << "Error opening file." << endl;
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        fout << "Hello." << endl;
        if (!fout) {
            cout << "Error writing to file." << endl;
            return 1;
        }
    }

    return 0;
}

