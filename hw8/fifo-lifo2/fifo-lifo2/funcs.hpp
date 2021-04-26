/**
 filename:	funcs.hpp
 author:	Nick Wirak
 date:		2/23/2021
 summary:
	FifoPush:			Takes a string and container. Pushes string to container.
	FifoPop:			Takes a string and container. Pops the item from the container
						that was least recently added to it into the string.
	LifoPush:			Takes a string and container. Pushes string to container.
						same functionality as FifoPush().
	LifoPop:			Takes a string and container. Pops the item from the container
						that was most recently added to it into the string.
	IsContainerEmpty:	Takes a vector. If vector has size zero, returns true. If the
						vector has size greater than zero, returns false.
	PrintContainer:		Takes a vector of strings. Prints each string on a new line.
						Also indents strings with three spaces to make the resulting
						list easier to read.
	TestFifo:			Automatically pushes a sequence of strings to a vector. The
						sequence is defined in the source code. Then automatically pops,
						according to fifo, the strings from the first vector to a second
						vector. The resulting sequence of strings is checked against a
						known correct sequence defined in the source code. No inputs are
						necessary to verify fifo functionality.
	TestLifo:			Automatically pushes a sequence of strings to a vector. The
						sequence is defined in the source code. Then automatically pops,
						according to lifo, the strings from the first vector to a second
						vector. The resulting sequence of strings is checked against a
						known correct sequence defined in the source code. No inputs are
						necessary to verify lifo functionality.
*/

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
