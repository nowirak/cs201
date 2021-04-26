
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
	void remove(size_t index);				//want to add
	void add(size_t index, string add);		//want to add

private:
	DoubleLink* _back;
	DoubleLink* _current;
	DoubleLink* _front;
	size_t _size;

};

#endif // !FUNCS_HPP
