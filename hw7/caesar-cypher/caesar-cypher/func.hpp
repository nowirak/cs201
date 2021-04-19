
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
