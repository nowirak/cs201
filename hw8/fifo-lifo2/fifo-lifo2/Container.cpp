/**
 filename:	Container.cpp
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

#include "Container.hpp"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;


////   CONSTRUCTORS / DESTRUCTORS   ////
Container::Container() : _container(0) {}
Container::Container(const vector<string>& input) : _container(input) {}
Container::~Container() {}


////   MEMBER FUNCTIONS   ////
void Container::fifoPush(const string& item) {
	_container.push_back(item);
	return;
}

//The approach to fifopops here is to rewrite and resize a vector
//after every pop. This allows for easy indexing, and ideal vector
//size. The downside is every vector element has to be overwritten
//by another. Fifopops take place at the front of a vector, unlike
//the other operations here.
void Container::fifoPop(string& item) {
	item = _container.at(0);
	for (int i = 0; i < _container.size() - 1; i++) {
		_container.at(i) = _container.at(i + 1);

	}
	_container.resize(_container.size() - 1);
	return;
}

void Container::lifoPush(const string& item) {
	_container.push_back(item);
	return;
}

void Container::lifoPop(string& item) {
	item = _container.back();
	_container.pop_back();
	return;
}

bool Container::isContainerEmpty() {
	return _container.size() == 0;
}

void Container::printContainer() {
	for (int i = 0; i < _container.size() - 1; i++) {
		cout << "   " << _container.at(i) << endl;
	}
	cout << "   " << _container.at(_container.size() - 1);
	return;
}
