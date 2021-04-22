
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
using std::string;

class Student {
	const string _name;
	const unsigned int _id;
public:
	Student(): _name("_"), _id(0) {}
	Student(string name) : _name(name), _id(0) {}
	Student(string name, unsigned int id) :
		_name(name),
		_id(id) {}

	~Student() {}

	void printInfo() const;
};

#endif