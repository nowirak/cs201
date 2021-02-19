// bulls-and-cows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;



int main()
{
    std::vector<char> number{ '1','2','3','4' };
    std::string input;
    int bulls;
    int cows;
    bool isInt;

    do {
        cout << "Enter four positive digits to guess," << endl;
        cout << "   or a negative number to show solution: ";
        cin >> input;

        isInt = true;
        bulls = 0;
        cows = 0;
        
        if (input.front() == '-') {
            if (input.at(1) == '0') {
                cout << endl << "***You did not enter four digits or a negative number.***" << endl << endl;
                continue;
            }
            for (int i = 1; i < input.size(); i++) {
                if (input.at(i) < '0' || input.at(i) > '9') {
                    isInt = false;
                    break;
                }
            }
            if (isInt == true) {
                cout << endl << "Solution: " << number.at(0) << number.at(1)
                    << number.at(2) << number.at(3) << endl;
                break;
            }
        }

        if (input.size() != 4) {
            cout << endl << "***You did not enter four digits or a negative number.***" << endl << endl;
            continue;
        }

        for (int i = 0; i < input.size(); i++) {
            if (input.at(i) < '0' || input.at(i) > '9') {
                cout << endl << "***You did not enter four digits or a negative number.***" << endl << endl;
                isInt = false;
                break;
            }
            for (int j = 0; j < number.size(); j++) {
                if (input.at(i) == number.at(j)) {
                    if (i == j)
                        bulls++;
                    else
                        cows++;
                }
            }
        }

        if (isInt == false)
            continue;
        else if (bulls == 4) {
            cout << endl << "Correct." << endl;
            break;
        }
        else {
            cout << endl << "Bulls: " << bulls << endl;
            cout << "Cows: " << cows << endl << endl;
        }

    } while (true);

    return 0;
}

