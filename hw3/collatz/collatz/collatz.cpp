/**
 filename:	collatz.cpp
 author:	Nick Wirak
 date:		2/9/2021
 summary:	Queries user to enter a positive integer. Error checks user input and if 
            necessary asks for reentry. Prints Collatz sequence. Repeats until user 
            chooses to quit.
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

//implementation of the collatz function
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

    while (true) {
        cout << "Enter a positive integer or '0' to quit: ";
        cin >> user;

        //user input check and forced integer reentry
        while (user < 0) {
            cout << "***Please enter a positive integer or '0' to quit: ";
            cin >> user;
        }

        if (user == 0)  //quit collatz sequence print routine if necessary
            break;

        cout << endl << "Collatz sequence: " << endl;

        //print collatz sequence by iterative calls to the collatz function.
        //avoids printing 'space' at the end of the sequence.
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

        cout << endl << endl;
    }

    return 0;
}
