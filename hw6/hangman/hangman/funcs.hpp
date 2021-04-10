/**
 filename:	funcs.hpp
 author:	Nick Wirak
 date:		4/09/2021
 summary:
	get_word:	Produces a psuedorandom choice of an element of a vector<string>. Assumes
				the size of the vector is at least 1.

	word_list:	A constant list of 30 words found using a random online generator. The 
				list might be used as a word source for word-guessing games.

*/

#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <vector>
using std::vector;
#include <string>
using std::string;

vector<string> word_list
{ "ice", "spiders", "giants", "page", "petite",
	"gentle", "functional", "communicate", "homely", "education",
	"greet", "weight", "flow", "canvas", "astonishing",
	"eggnog", "succeed", "servant", "step", "imperfect",
	"drawer", "effect", "fetch", "sparkle", "stranger",
	"obscene", "language", "temporary", "sleet", "brainy" };


string get_word(const vector<string> &word_list);



#endif
