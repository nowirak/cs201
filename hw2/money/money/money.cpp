/**
* filename: names.cpp
* author:   Nick Wirak
* date:     1/29/2021
* summary:  Prompts user to enter different amounts of
*           coin denominations. Returns to user the coin amounts
*           as they were entered, and the dollar total of their
*           coins.
*/

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::cin;

int main()
{
     std::vector<std::string> denoms{ "null", "pennies", "penny", "nickels",
        "nickel", "dimes", "dime", "quarters", "quarter", "half dollars",
        "half dollar" };
    std::vector<int> amounts (6);
    int cents;

    cout << "Your Money...(enter integers 0 or larger)" << endl;

    //User input validation. Assumes integer input, but
    //forces integers greater than or equal to zero.
    for (int i = 1; i < 6; i++) {
        cout << "Total " << denoms[2*i-1] << ": ";
        cin >> amounts[i];
        while (amounts[i] < 0) {
            cout << "   Re-enter a valid number: ";
            cin >> amounts[i];
        }
    }

    //Returns the list entered by the user to the user
    //for verification (without recourse).
    cout << endl;
    for (int i = 1; i < 6; i++) {
        if (amounts[i] == 1)
            cout << "You have " << amounts[i] << " " << denoms[2 * i] << "." << endl;
        else
            cout << "You have " << amounts[i] << " " << denoms[2 * i-1] << "." << endl;
    }

    //Calculate total currency in cents.
    cout << endl;
    cents = (amounts[1] + 5 * amounts[2] + 10 * amounts[3] +
        25 * amounts[4] + 50 * amounts[5]);

    //Determine if only one coin was entered, and conditionally
    //output appropriate grammar.
    if ((amounts[1] + amounts[2] + amounts[3] + amounts[4] + amounts[5]) == 1)
        cout << "The value of your coin is $";
    else
        cout << "The value of all your coins is $";
    
    //Calculate and output dollars
    cout << cents / 100 << ".";

    //Calculate and output cents with a '0' for cent amounts
    //less than 10.
    if (cents % 100 < 10)
        cout << "0" << cents % 100 << "." << endl;
    else
        cout << cents % 100 << "." << endl;

    return 0;
}
