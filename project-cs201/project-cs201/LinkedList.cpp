
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

void LinkedList::remove(size_t index) {

}

void LinkedList::add(size_t index, string add) {

}

