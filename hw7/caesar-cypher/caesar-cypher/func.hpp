/**
 filename:	func.hpp
 author:	Nick Wirak
 date:		4/20/2021
 summary:
	caesarCypher:	Effectively implements a caesar cypher with a key of 1, or a single
					cycle of a cypher with a key value greater than 1. Shifts ascii
					characters 'A'-'Y' and 'a'-'y' up by 1, and 'Z' to 'A' and 'z' to 
					'a' when found in a string.

*/

#include<string>
using std::string;

#ifndef FUNC_HPP
#define FUNC_HPP

// Note: as an inline function, this could not be defined in a separate source file.
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
