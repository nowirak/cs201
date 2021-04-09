// random-map.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
    //get random word from a word list. input the word list. the word list should
    //not be empty
    string word (get_word(word_list));
    string word_complete (word.size(), '*');

    cout << "In this program, you will play hangman. A word has been selected" << endl;
    cout << "of the following form: " << word_complete << endl;
    cout << "You have 10 guesses to complete the word. Guesses should be in" << endl;
    cout << "the form of a single lower-case letter." << endl << endl;

    cout << "Begin..." << endl;

    map<char, bool> storage;
    string user;
    int guess = 0;
	while (true) {
		cout << "guess> ";
        getline(cin, user);
        if (user.size() != 1) {
            cout << "*** '" << user << "' is not a valid guess (not a lower case letter)." << endl;
            cout << "      Try again." << endl << endl;
            continue;
        }
        else if (user.at(0) > 122 || user.at(0) < 97) {
            cout << "*** '" << user << "' is not a valid guess (not a lower case letter)." << endl;
            cout << "      Try again." << endl << endl;
            continue;
        }
        
        if (storage.count(user.at(0)) != 0) {
            cout << "*** You have already guessed '" << user << "'. Try again." << endl << endl;
            continue;
        }


        if (std::count(word.begin(), word.end(), user.at(0)) == 0) {
            storage[user.at(0)] = 0;
            guess++;
            if (guess == 10) {
                cout << "Sorry. You have used 10 guesses, and lost the game." << endl << endl;
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

        cout << "Here is the word state now: " << word_complete << endl;
        if (std::count(word_complete.begin(), word_complete.end(), '*') == 0) {
            cout << "Congradulations. You won the game." << endl << endl;
            break;
        }
        cout << "You have " << 10 - guess << " guesses remaining." << endl << endl;
	}


    return 0;
}

