/**
 filename:	hangman.cpp
 author:	Nick Wirak
 date:		4/09/2021
 summary:   Play a single game of hangman. No visual representation of the game is 
            implemented, however, the game allows the user 10 incorrect guesses to
            complete a word. The user is not limited by the number of correct guesses
            they make. The program informs the user of input errors and repeat 
            guesses. The user most complete the game by winning or losing for the program
            to exit and close.

*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>;
using std::map;
#include <algorithm>
#include <sstream>
using std::istringstream;


#include "funcs.hpp"


int main()
{
    //Get random word from a word list. Input the word list. The word list should
    //not be empty.
    string word (get_word(word_list));
    string word_complete (word.size(), '*'); //Stores current user progression in the game.

    //Output program description and user instructions.
    cout << "In this program, you will play hangman. A word has been selected" << endl;
    cout << "of the following form: " << word_complete << endl;
    cout << "You have 10 guesses to complete the word. Guesses should be in" << endl;
    cout << "the form of a single lower-case letter." << endl << endl;

    cout << "Begin..." << endl;

    //Main game loop for a single game of hangman.
    map<char, bool> storage;
    string user;
    int guess = 0;
	while (true) {
        //Collect user input, which takes only the form of an invalid entry or valid
        //guess.
		cout << "guess> ";
        getline(cin, user);

        //Check if user entry is a valid guess. If not, reset to query for a new guess.
        if (user.size() != 1) {
            cout << "*** '" << user << "' is not a valid guess (not a lower case letter).";
            cout << endl;
            cout << "      Try again." << endl << endl;
            continue;
        }
        else if (user.at(0) > 122 || user.at(0) < 97) {
            cout << "*** '" << user << "' is not a valid guess (not a lower case letter).";
            cout << endl;
            cout << "      Try again." << endl << endl;
            continue;
        }
        
        //Check if valid guess has already been guessed previously. If yes, reset
        //to query user for a new guess. No other gameplay implications.
        if (storage.count(user.at(0)) != 0) {
            cout << "*** You have already guessed '" << user << "'. Try again.";
            cout << endl << endl;
            continue;
        }

        //Check if a valid new guess is in the mystery word. Advance game appropriately.
        //Ends game if user has lost.
        if (std::count(word.begin(), word.end(), user.at(0)) == 0) {
            storage[user.at(0)] = 0;
            guess++;
            if (guess == 10) {
                cout << "Sorry. You have used all 10 guesses, and lost the game.";
                cout << endl << endl;
                break;
            }
        }
        else {
            storage[user.at(0)] = true;

            std::replace_copy_if(word.begin(), word.end(), word_complete.begin(),
                [&storage](const char &a) {
                    if (storage.count(a) == 0) {
                        return true;
                    }
                    else {
                        return !storage[a];
                    }
                }, '*');
        }

        //Inform user of current word state for next guess/check cycle.
        cout << "Here is the word state now: " << word_complete << endl;

        //Check if the game should end because the user has won.
        if (std::count(word_complete.begin(), word_complete.end(), '*') == 0) {
            cout << "Congradulations. You won the game." << endl << endl;
            break;
        }

        //Inform user of how many incorrect guess that they are still allowed before 
        //losing.
        cout << "You have " << 10 - guess << " guesses remaining." << endl << endl;
	}


    return 0;
}

