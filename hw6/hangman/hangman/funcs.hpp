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
