
#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>	

bool ReadLine(std::string& str);

unsigned StringToTokensWS(const std::string& input,
	std::vector<std::string>& tokens);

void AnalyzeTokens(const std::vector<std::string>& tokens);

#endif