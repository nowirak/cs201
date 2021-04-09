
#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <map>
using std::map;
#include <string>
using std::string;


struct Record {
	double unitPrice;
	int units;
};


void printInventory(const map<string, Record> &inventory);


void printCart(const map<string, Record>& cart);


#endif