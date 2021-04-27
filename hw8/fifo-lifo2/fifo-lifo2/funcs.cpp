/**
 filename:	funcs.cpp
 author:	Nick Wirak
 date:		4/26/2021
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

#include "funcs.hpp"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;



//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////



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



//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////



bool TestFifo() {
	vector<string> testPushSeq{ "push \"A\"", "push \"B\"", "push \"C\"", "push \"D\"" };
	vector<string> testPopSeq{ "pop", "pop", "pop", "pop" };
	vector<string> correctReturn{ "A", "B", "C", "D" };
	Container storage;
	vector<string> returnSeq;

	//Read instruction and push string if appropriate.
	for (int i = 0; i < 4; i++) {
		if (testPushSeq.at(i).size() >= 7 && testPushSeq.at(i).substr(0, 6) == "push \"" &&
			testPushSeq.at(i).back() == '"') {
			storage.fifoPush(testPushSeq.at(i).substr(6, testPushSeq.at(i).size() - 7));
		}
		else {
			return 0;
		}
	}

	//Read instruction and pop string if appropriate.
	for (int i = 0; i < 4; i++) {
		if (testPopSeq.at(i) == "pop") {
			returnSeq.resize(i + 1);
			storage.fifoPop(returnSeq.at(i));
		}
		else {
			return 0;
		}
	}

	//Check returned sequence against the know correct sequence.
	//Return 0 if there is any inconsistency, return 1 if test
	//is passed.
	for (int i = 0; i < 4; i++) {
		if (returnSeq.at(i) != correctReturn.at(i))
			return 0;
		else
			return 1;
	}
}

bool TestLifo() {
	vector<string> testPushSeq{ "push \"A\"", "push \"B\"", "push \"C\"", "push \"D\"" };
	vector<string> testPopSeq{ "pop", "pop", "pop", "pop" };
	vector<string> correctReturn{ "D", "C", "B", "A" };
	Container storage;
	vector<string> returnSeq;

	//Read instruction and push string if appropriate.
	for (int i = 0; i < 4; i++) {
		if (testPushSeq.at(i).size() >= 7 && testPushSeq.at(i).substr(0, 6) == "push \"" &&
			testPushSeq.at(i).back() == '"') {
			storage.lifoPush(testPushSeq.at(i).substr(6, testPushSeq.at(i).size() - 7));
		}
		else {
			return 0;
		}
	}

	//Read instruction and pop string if appropriate.
	for (int i = 0; i < 4; i++) {
		if (testPopSeq.at(i) == "pop") {
			returnSeq.resize(i + 1);
			storage.lifoPop(returnSeq.at(i));
		}
		else {
			return 0;
		}
	}

	//Check returned sequence against the know correct sequence.
	//Return 0 if there is any inconsistency, return 1 if test
	//is passed.
	for (int i = 0; i < 4; i++) {
		if (returnSeq.at(i) != correctReturn.at(i))
			return 0;
		else
			return 1;
	}
}
