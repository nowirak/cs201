/**
* filename: names.cpp
* author:   Nick Wirak
* date:     1/29/2021
* summary:  write stuff
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

    for (int i = 1; i < 6; i++) {
        cout << "Total " << denoms[2*i-1] << ": ";
        cin >> amounts[i];
        while (amounts[i] < 0) {
            cout << "   Re-enter a valid number: ";
            cin >> amounts[i];
        }
    }

    cout << endl;
    for (int i = 1; i < 6; i++) {
        if (amounts[i] == 1)
            cout << "You have " << amounts[i] << " " << denoms[2 * i] << "." << endl;
        else
            cout << "You have " << amounts[i] << " " << denoms[2 * i-1] << "." << endl;
    }

    cout << endl;
    cents = (amounts[1] + 5 * amounts[2] + 10 * amounts[3] +
        25 * amounts[4] + 50 * amounts[5]);
    if ((amounts[1] + amounts[2] + amounts[3] + amounts[4] + amounts[5]) == 1)
        cout << "The value of your coin is $";
    else
        cout << "The value of all your coins is $";
    cout << cents / 100 << ".";
    if (cents % 100 < 10)
        cout << "0" << cents % 100 << "." << endl;
    else
        cout << cents % 100 << "." << endl;

    return 0;
}
