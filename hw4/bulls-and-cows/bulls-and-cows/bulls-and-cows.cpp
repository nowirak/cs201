/**
 filename:	bulls-and-cows.cpp
 author:	Nick Wirak
 date:		2/23/2021
 summary:	Implementation of the guessing game bulls-and-cows. The user can
            guess a four digit number only. Their guess can include repeated 
            digits. Any user input other than a four digit postive number is
            not a valid guess. Negative numbers of any length will trigger 
            the end of the game, and the solution will be shown.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<char> number{ '1','2','3','4' };    //The solution is hard-coded.
    std::string input;
    int bulls;
    int cows;
    bool isInt;

    //The main program loop that repeated verifies user input and respones
    //accordingly.
    do {
        cout << "Enter four positive digits to guess," << endl;
        cout << "   or a negative number to show solution: ";

        //This sequence somehow clears the buffer so to speak, so that users
        //cannot space delineate inputs, which throws off formatting because
        //less newlines result.
        cin.seekg(0, ios::end);
        cin.clear();
        //
        cin >> input;

        isInt = true;
        bulls = 0;
        cows = 0;
        
        //This block handles the situation when the user enters '-' at the
        //beginning of their entry as if trying to get the solution. The input
        //is checked to force the entry of a valid negative number.
        if (input.front() == '-') {
            if (input.size() == 1) {
                cout << endl << "***You did not enter four digits or a negative number.***" << endl << endl;
                continue;
            }
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

        //After checking for a negative number, any other valid input must be 
        //4 digits in length.
        if (input.size() != 4) {
            cout << endl << "***You did not enter four digits or a negative number.***" << endl << endl;
            continue;
        }

        //If the program has gotten to this block, it will subsequently check
        //that all four digits of the entry are numbers. If not, generic error
        //message and user must reenter. If yes, then bulls and cows are computed
        //from the entry.
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
        else if (bulls == 4) {  //If 4 bulls, the number is correct.
            cout << endl << "Correct." << endl;
            break;
        }
        //Report to the user the number of bulls and cows in their latest entry.
        else {
            cout << endl << "Bulls: " << bulls << endl;
            cout << "Cows: " << cows << endl << endl;
        }

    } while (true);

    return 0;
}

