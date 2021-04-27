/**
 filename:	Container.hpp
 author:	Nick Wirak
 date:		4/26/2021
 summary:	Class to hold a vector of strings and perform queue and stack operations.

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
*/

#ifndef CONTAINER_HPP
#define CONTAINER_HPP


#include <vector>
#include <string>
using std::string;
using std::vector;

class Container {
public:
	Container();
	Container(const vector<string>& input);
	~Container();

	void fifoPush(const string& item);
	void fifoPop(string& item);
	void lifoPush(const string& item);
	void lifoPop(string& item);
	bool isContainerEmpty();
	void printContainer();
private:
	vector<string> _container;
};


#endif // !CONTAINER_HPP
