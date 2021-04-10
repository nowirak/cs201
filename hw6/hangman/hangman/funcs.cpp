/**
 filename:	funcs.cpp
 author:	Nick Wirak
 date:		4/09/2021
 summary:	start

*/

#include <random>
using std::mt19937;
using std::uniform_int_distribution;
using std::random_device;
#include <vector>
using std::vector;
#include <string>
using std::string;




string get_word(const vector<string>& word_list)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distrib(0, word_list.size() - 1);

	return word_list.at(distrib(gen));
}

