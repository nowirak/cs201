/**
 filename:	LinkedList.hpp
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

#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <string>
using std::string;

struct DoubleLink {

	DoubleLink() : ptrBack(nullptr), userString(""), ptrForward(nullptr) {}
	~DoubleLink() {}

	DoubleLink* ptrBack;
	string userString;
	DoubleLink* ptrForward;
};

class LinkedList {
public:
	LinkedList();
	LinkedList(size_t size);
	~LinkedList();

	size_t size() const;
	bool isEmpty() const;
	void print();
	void backAdd();
	void backAdd(string add);
	void frontAdd();
	void frontAdd(string add);
	void backRemove();
	void frontRemove();
	void listDelete();
	//void remove(size_t index);				//want to add
	// void add(size_t index, string add);		//want to add

private:
	DoubleLink* _back;
	DoubleLink* _current;
	DoubleLink* _front;
	size_t _size;

};

#endif // !FUNCS_HPP
