/**
 filename:	funcs.hpp
 author:	Nick Wirak
 date:		4/20/2021
 summary:
	get_word:	Produces a psuedorandom choice of an element of a vector<string>. Assumes
				the size of the vector is at least 1.

	word_list:	A constant list of 30 words found using a random online generator. The
				list might be used as a word source for word-guessing games.

*/

#include<string>
using std::string;

#ifndef FUNC_HPP
#define FUNC_HPP

inline void caesarCypher(string& text) {
	for (size_t i = 0; i < text.size(); i++) {
		if ((text.at(i) >= 65 && text.at(i) <= 89) ||
			(text.at(i) >= 97 && text.at(i) <= 121)) {
			text.at(i) = text.at(i)++;
		}
		else if (text.at(i) == 90) {
			text.at(i) = 65;
		}
		else if (text.at(i) == 122) {
			text.at(i) = 97;
		}
	}
	return;
}

#endif // !FUNC_HPP
