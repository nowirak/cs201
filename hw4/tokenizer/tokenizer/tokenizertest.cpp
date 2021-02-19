
#include "tokenizer.hpp"
#include <iostream>

int main() {

	std::string str;
	std::vector<std::string> tokens;
	unsigned int count = 0;

	std::cout << "Please type in some text. When you are" <<
	" done, type \"end\":" << std::endl;

	do {
		ReadLine(str);
		count = count + StringToTokensWS(str, tokens);
	} while (tokens.at(tokens.size()-2) != "end");

	tokens.pop_back();
	count--;
	AnalyzeTokens(tokens);

	return 0;
}