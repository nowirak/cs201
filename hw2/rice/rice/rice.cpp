/**
* filename: names.cpp
* author:   Nick Wirak
* date:     1/29/2021
* summary:  write stuff
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    int total = 1;
    int square = 1;

    cout << "Powers of 2 follow the sums of powers." << endl;
    cout << total << "  " << square << endl;
    for (int i = 2; i < 65; i++) {
        
        square = square * 2;

        if(total + square > 1000) {

            if (total < 1000) {
                total = total + square;
                cout << total << "  " << square << endl;
                cout << "Number of squares for at least 1,000 grains: ";
                cout << i << endl;
                continue;
            }

            if (total + square > 1000000) {

                if (total < 1000000) {
                    total = total + square;
                    cout << total << "  " << square << endl;
                    cout << "Number of squares for at least 1,000,000 grains: ";
                    cout << i << endl;
                    continue;
                }

                if (total > 1000000000) {
                    cout << "Number of squares for at least 1,000,000,000 grains: ";
                    cout << i-1 << endl;
                    break;
                }

                total = total + square;
                cout << total << "  " << square << endl;
                continue;

            }

            total = total + square;
            cout << total << "  " << square << endl;
            continue;
        }

        total = total + square;
        cout << total << "  " << square << endl;
    }

    cout << endl << "Maximum using int:" << endl;
    total = 1;
    square = 1;

    for (int i = 2; i < 34; i++) {
        square = square * 2;
        total = total + square;
        cout << total << endl;
    }

    cout << endl << "You can calculate rice exactly for 31 squares." << endl;


    cout << endl << "Approximate maximum using double:" << endl;

    double dtotal = 1;
    double dsquare = 1;

    //cout.precision(17);

    for (int i = 2; i < 1026; i++) {
        dsquare = dsquare * 2;
        dtotal = dtotal + dsquare;
        cout << dtotal << endl;
    }
        
    cout << endl << "You can calculate the rice approximately for 1023 squares." << endl;

    return 0;
}
