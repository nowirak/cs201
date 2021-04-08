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



    cout << "guess> ";



    //get input






    map<char, bool> user_guess;



    return 0;
}

