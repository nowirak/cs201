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

#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>	

bool ReadLine(std::string& str);

unsigned StringToTokensWS(const std::string& input,
	std::vector<std::string>& tokens);

void AnalyzeTokens(const std::vector<std::string>& tokens);

#endif