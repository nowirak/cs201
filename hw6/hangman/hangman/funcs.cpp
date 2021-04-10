/**
 filename:	funcs.cpp
 author:	Nick Wirak
 date:		4/09/2021
 summary:
	get_word:	Produces a psuedorandom choice of an element of a vector<string>. Assumes
				the size of the vector is at least 1.

	word_list:	A constant list of 30 words found using a random online generator. The
				list might be used as a word source for word-guessing games.

*/

#include <random>
using std::mt19937;
using std::uniform_int_distribution;
using std::random_device;
#include <vector>
using std::vector;
#include <string>
using std::string;

//note that funcs.hpp could not be declared here because a repeat definition of the
//word list in it would be made. this leads can lead to repeated file inclusions here.
//a possible solution is to create an additional header file with the word list defined
//there.


string get_word(const vector<string>& word_list)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distrib(0, word_list.size() - 1);

	return word_list.at(distrib(gen));
}

