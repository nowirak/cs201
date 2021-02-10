// collatz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

inline int collatz(int n) {
    if (n % 2 == 0)
        return n / 2;
    else
        return 3 * n + 1;
}

int main()
{
    int user;
    int temp;

    cout << "Enter a positive integer: ";
    cin >> user;

    while (user < 1) {
        cout << "***Please enter a positive integer: ";
        cin >> user;
    }

    cout << endl << "Collatz sequence: " << endl;

    cout << user;
    if (user != 1) {
        temp = collatz(user);
        cout << " " << temp;
        while (temp != 1) {
            cout << " ";
            temp = collatz(temp);
            cout << temp;
        }
    }

    cout << endl;

    return 0;
}

