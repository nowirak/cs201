
#include <iostream>
using std::cout;
using std::endl;
#include "student.hpp"

void Student::printInfo() const
{
	cout << "Name: " << _name << ", id: " << _id << ")" << endl;
}