/**
 filename:	tokenizertest.cpp
 author:	Nick Wirak
 date:		2/22/2021
 summary:	
	ReadLine:			Performs getline(). Returns 0 if the string read is empty.
	StringToTokensWS:	Extract tokens from a line of user input. The extracted tokens
						are added to a vector that holds tokens.
	AnalyzeTokens:		Analyze a vector of tokens to determine token type. Types are
						'integer', 'identifier', 'string', 'whitespace', 'unknown', and 
						'other'. The types are not saved, but are printed in an array
						for the user, along with their corresponding token.
*/

#include "tokenizer.hpp"
#include <iostream>
#include <sstream>

bool ReadLine(std::string& str) {

	std::getline(std::cin, str);
	return str.size() == 0;

}

unsigned int StringToTokensWS(const std::string& input,
	std::vector<std::string>& tokens) {
	
	std::istringstream full(input);
	std::string str ("");
	unsigned int count = 0;

	full >> str;

	if (str.size() == 0) {
		tokens.push_back("");
		return 1;
	}

	while (str.size() != 0) {
		tokens.push_back(str);
		count ++;
		//Used to determine whether anything new token has been added.
		//If not, the line has been found to be ended by the user.
		str = "";
		full >> str;
	}

	//Blank string pushback at the end of line.
	tokens.push_back("");
	count++;

	return count;

}

void AnalyzeTokens(const std::vector<std::string>& tokens) {
	
	bool test;
	
	for (auto m : tokens) {
		
		test = true;

		//Whitespace.
		if (m.size() == 0) {
			std::cout << "[whitespace]" << "      " << "\"" << m << "\"" << std::endl;
			continue;
		}

		//String.
		else if (m.front() == '"' && m.back() == '"') {
			std::cout << "[string]" << "          " << m << std::endl;
			continue;
		}

		//Integer.
		else if (m.front() >= '0' && m.front() <= '9') {
			for (int i = 1; i < m.size(); i++) {
				if (m.at(i) < '0' || m.at(i) > '9') {
					test = false;
					break;
				}
			}
			if (test == true) {
				std::cout << "[integer]" << "         " << "\"" << m << "\"" << std::endl;
			}
		}

		//Identifier.
		for (int i = 0; i < m.size(); i++) {
			if (m.at(i) != '_') {
				if (m.at(i) < 'A' || m.at(i) > 'Z') {
					if (m.at(i) < 'a' || m.at(i) > 'z') {
						test = false;
						break;
					}
				}
			}
		}
		if (test == true) {
			std::cout << "[identifier]" << "      " << "\"" << m << "\"" << std::endl;
		}
		
		//Other.
		else if (m.size() == 1) {
			switch (m.front()) {
			case '+':
			case '-':
			case '*':
			case '/':
			case '=':
			case '%':
				std::cout << "[other]" << "           " << "\"" << m << "\"" << std::endl;
				break;
			default:
				break;
			}
			continue;
		}

		//Unknown.
		else {
			std::cout << "[unknown]" << "         " << "\"" << m << "\"" << std::endl;
		}
	}
}