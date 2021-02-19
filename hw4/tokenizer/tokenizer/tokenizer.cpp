// tokenizer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
		str = "";
		full >> str;
	}

	tokens.push_back("");
	count++;

	return count;

}

void AnalyzeTokens(const std::vector<std::string>& tokens) {
	
	bool test;
	
	for (auto m : tokens) {
		
		test = true;

		if (m.size() == 0) {
			std::cout << "[whitespace]" << "      " << "\"" << m << "\"" << std::endl;
			continue;
		}

		else if (m.front() == '"' && m.back() == '"') {
			std::cout << "[string]" << "          " << m << std::endl;
			continue;
		}

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

		
		for (int i = 1; i < m.size(); i++) {
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

		else {
			std::cout << "[unknown]" << "         " << "\"" << m << "\"" << std::endl;
		}
	}
}