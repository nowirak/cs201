/**
 filename:	funcs.hpp
 author:	Nick Wirak
 date:		4/09/2021
 summary:
	PrintInventory:	Takes a map with strings representing store items for sale as keys
					and a struct with item information as the second element of the pairs.
					Prints formatted item and unit pricing information. For purposes
					of a shopper, so does not disclose store inventory of each item.

	PrintCart:		Takes a map with strings representing store items for sale as keys
					and a struct with item information as the second element of the pairs.
					Prints formatted item and proposed sales volume of the item (amount
					to be purchased). Calculates and prints a sales total below cart
					printout.

*/

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