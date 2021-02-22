
#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <vector>
#include <string>
using std::string;
using std::vector;

void FifoPush(vector<string>& container, const string& item);

void FifoPop(vector<string>& container, string& item);

void LifoPush(vector<string>& container, const string& item);

void LifoPop(vector<string>& container, string& item);

bool IsContainerEmpty(const vector<string>& container);

void PrintContainer(const vector<string>& container);

bool TestFifo();

bool TestLifo();

#endif // !FUNCS_HPP
