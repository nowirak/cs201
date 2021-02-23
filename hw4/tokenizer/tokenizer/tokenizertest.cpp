/**
 filename:	tokenizertest.cpp
 author:	Nick Wirak
 date:		2/22/2021
 summary:	The user is prompted to type some text. The user can continue to
			enter lines of text until the words (delineated by white space)
			'end' or 'End' or 'END' appear in a line of their text. After a 
			stop is initiated in this fashion, the program prints out, line
			by line, the individual tokens that were entered by the user in 
			the previous program step.
*/

#include "tokenizer.hpp"
#include <iostream>

int main() {

	std::string str;
	std::vector<std::string> tokens;
	unsigned int count = 0;
	unsigned int count2 = 0;

	//Output of user instructions.
	std::cout << "Please type in some text. When you are" <<
	" done, type \"end\" or \"End\" or \"END\":" << std::endl;

	//Loop to continue gathering user text, line-by-line. In the loop,
	//a line is read, then conversion tokens is performed. The number
	//of tokens taken from a line is recorded to use for a user request
	//to exit.
	while (true) {
		ReadLine(str);
		count2 = StringToTokensWS(str, tokens);
		count = count + count2;
		if (count2 == 2) {
			if (tokens.at(tokens.size() - 2) == "end" || tokens.at(tokens.size() - 2) ==
				"End" || tokens.at(tokens.size() - 2) == "END") {
				break;
			}
		}
	}

	//Eliminate extra whitespace and count gathered at the end of user
	//input. The extra whitespace was not desireable according to the 
	//exercise instructions.
	tokens.pop_back();
	count--;

	//Analyze and print tokens along with their type determined by the 
	//analysis.
	AnalyzeTokens(tokens);

	return 0;
}