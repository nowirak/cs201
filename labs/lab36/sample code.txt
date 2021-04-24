// sandwich.cpp
// Glenn G. Chappell
// 16 Apr 2018
//
// For CS 201 Spring 2018
// Sandwich Toppings - Passing Flags in an int

#include <iostream>
using std::cout;
using std::endl;
using std::cin;


// Bit masks for various sandwich toppings
const int LETTUCE = 1;
const int TOMATO = 2;
const int PICKLE = 4;
const int ONION = 8;
const int MAYO = 16;
const int MUSTARD = 32;


// sandwich
// Given int "toppings", with bits having meanings as above, print all
// sandwich toppings specified, on a single line, or "(none)" if none
// specified.
void sandwich(int toppings)
{
    cout << "Toppings:";

    if ((toppings & LETTUCE) != 0)
        cout << " lettuce";
    if ((toppings & TOMATO) != 0)
        cout << " tomato";
    if ((toppings & PICKLE) != 0)
        cout << " pickle";
    if ((toppings & ONION) != 0)
        cout << " onion";
    if ((toppings & MAYO) != 0)
        cout << " mayonnaise";
    if ((toppings & MUSTARD) != 0)
        cout << " mustard";

    if (toppings == 0)
        cout << " (none)";

    cout << endl;
}


// Main Program
// Call function "sandwich" to specify sandwiches with various
// combinations of toppings.
int main()
{
    cout << "Sandwich #1" << endl;
    sandwich(LETTUCE | ONION);
    cout << endl;

    cout << "Sandwich #2" << endl;
    sandwich(TOMATO | ONION | MAYO);
    cout << endl;

    cout << "Sandwich #3 - all toppings" << endl;
    sandwich(LETTUCE | TOMATO | PICKLE | ONION | MAYO | MUSTARD);
    cout << endl;

    cout << "Sandwich #4 - no toppings" << endl;
    sandwich(0);
    cout << endl;

    // Wait for user
    cout << "PRESS ENTER to quit ";
    while (cin.get() != '\n') ;
}
