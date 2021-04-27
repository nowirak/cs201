/**
 filename:	LinkedList.cpp
 author:	Nick Wirak (adapted from Dr. Genetti work)
 date:		4/27/2021
 summary:   Declarations of the DoubleLink data structure and LinkedList class. The
			DoubleLink objects are used integrally by LinkedLists items of the list.
			LinkedList implements a doubly linked list of strings.

	size():					Returns the size of the list.
	isEmpty():				Returns true if the size of the list is 0.
	print():				Prints the list of string contained within, each on a
							new line.
	backAdd():				Adds a blank string to the back of the list.
	backAdd(string add):	Adds the argument string to the back of the list.
	frontAdd():				Adds a blank string to the front of the list.
	frontAdd(string add):	Adds the argument string to the front of the list.
	backRemove():			Remove the string element from the back of the list.
	frontRemove():			Remove the string element from the front of the list.
	listDelete():			Delete all elements of the list. Final size of list is zero.

*/

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

#include "LinkedList.hpp"



////   CONSTRUCTORS / DESTRUCTORS   ////
LinkedList::LinkedList() : _size(0), _back(nullptr), _current(nullptr), _front(nullptr) {}

LinkedList::LinkedList(size_t size) {
	if (size <= 0) { _size = 0; _back = nullptr; _current = nullptr; _front = nullptr; }
	else {
		_size = size;
		_back = new DoubleLink;
		_current = _back;
		_front = _back;
		_back->ptrBack = _back;
		_back->ptrForward = _back;
		size--;
		while (size > 0) {
			_front = new DoubleLink;
			_current->ptrForward = _front;
			_front->ptrBack = _current;
			size--;
		}
		_front->ptrForward = _back;
		_back->ptrBack = _front;
	}
}

LinkedList::~LinkedList() {
	if (_size != 0) {
		for (int i = 0; i < _size; i++) {
			_current = _front;
			_front = _current->ptrBack;
			delete _current;
		}
	}
}



////   FUNCTIONS   ////
size_t LinkedList::size() const {
	return _size;
}

bool LinkedList::isEmpty() const {
	if (_size != 0) return false;
	else return true;
}

void LinkedList::print() {
	_current = _back;
	for (size_t i = 0; i < _size; i++) {
		cout << _current->userString << endl;
		_current = _current->ptrForward;
	}
	return;
}

void LinkedList::backAdd() {
	if (_size == 0) {
		_back = new DoubleLink;
		_current = _back;
		_front = _back;
		_back->ptrBack = _back;
		_back->ptrForward = _back;
	}
	else {
		_current = _back;
		_back = new DoubleLink;
		_current->ptrBack = _back;
		_back->ptrForward = _current;
		_back->ptrBack = _front;
	}
	_size++;
	return;
}

void LinkedList::backAdd(string add) {
	if (_size == 0) {
		_back = new DoubleLink;
		_current = _back;
		_front = _back;
		_back->ptrBack = _back;
		_back->ptrForward = _back;
	}
	else {
		_current = _back;
		_back = new DoubleLink;
		_current->ptrBack = _back;
		_back->ptrForward = _current;
		_back->ptrBack = _front;
	}
	_back->userString = add;
	_size++;
	return;
}

void LinkedList::frontAdd() {
	if (_size == 0) {
		_back = new DoubleLink;
		_current = _back;
		_front = _back;
		_back->ptrBack = _back;
		_back->ptrForward = _back;
	}
	else {
		_current = _front;
		_front = new DoubleLink;
		_current->ptrForward = _front;
		_front->ptrBack = _current;
		_front->ptrForward = _back;
	}
	_size++;
	return;
}

void LinkedList::frontAdd(string add) {
	if (_size == 0) {
		_back = new DoubleLink;
		_current = _back;
		_front = _back;
		_back->ptrBack = _back;
		_back->ptrForward = _back;
	}
	else {
		_current = _front;
		_front = new DoubleLink;
		_current->ptrForward = _front;
		_front->ptrBack = _current;
		_front->ptrForward = _back;
	}
	_front->userString = add;
	_size++;
	return;
}

void LinkedList::backRemove() {
	if (_size == 0) return;
	_current = _back->ptrForward;
	delete _back;
	_back = _current;
	_back->ptrBack = _front;
	_front->ptrForward = _back;
	_size--;
	if (_size == 0) {
		_back = nullptr;
		_current = nullptr;
		_front = nullptr;
	}
	return;
}

void LinkedList::frontRemove() {
	if (_size == 0) return;
	_current = _front->ptrBack;
	delete _front;
	_front = _current;
	_front->ptrForward = _back;
	_back->ptrBack = _front;
	_size--;
	if (_size == 0) {
		_back = nullptr;
		_current = nullptr;
		_front = nullptr;
	}
	return;
}

void LinkedList::listDelete() {
	auto temp(_size);
	for (int i = 0; i < temp; i++) {
		LinkedList::frontRemove();
	}
	return;
}

//void LinkedList::remove(size_t index) {}

//void LinkedList::add(size_t index, string add) {}

