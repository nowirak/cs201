/**
* filename: hw1_p2.cpp
* author:   Nick Wirak
* date:     1/29/2021
* summary:  Returns to user the greatest positive integer entered. User enter sequence terminated
*           by the entry of a non-positive integer.
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    int user;
    int greatest = 0;

    //user program instruction
    cout << "Enter a sequence of positive integers, ending with zero." << endl;
    cout << "I will print the greatest positive number entered." << endl;

    cout << endl << "Enter a positive integer (0 to end): ";
    cin >> user;

    //check for valid (positive integer) intial input
    if (user <= 0) {
        cout << endl << "No sequence of positive numbers was given." << endl;
        return 1;
    }
    
    //sequence collection and maximum integer check and save
    while (user > 0) {
        if (user > greatest)
            greatest = user;
        cout << "Enter a positive integer (0 to end): ";
        cin >> user;
    }

    cout << endl << "The greatest number entered was: " << greatest << endl << endl;

    return 0;
}
