/**
 filename:	funcs.cpp
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

#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
#include <ios>
#include <map>
using std::map;
#include <string>
using std::string;
#include<vector>
using std::vector;
#include<numeric>

#include "funcs.hpp"


void printInventory(const map<string, Record>& inventory) {
	int item_size = 0;

	for (const auto& p : inventory) {
		if (p.first.size() > item_size)
			item_size = p.first.size();
	}
	if (item_size < 14)
		item_size = 14;

	int item_pad = 10;

	cout << "Item";
	for (int i = 0; i < item_size - 4 + item_pad; i++) {
		cout << " ";
	}
	cout << "Unit Price ($)";
	cout << endl;
	for (int i = 0; i < item_size + item_pad + 14 + item_pad; i++) {
		cout << "*";
	}
	cout << endl;

	for (const auto& p : inventory) {
		cout << p.first;
		for (int i = 0; i < item_size - p.first.size() + item_pad; i++) {
			cout << " ";
		}
		cout << std::fixed << std::right << std::setw(13) << std::setprecision(2);
		cout << p.second.unitPrice;
		cout << endl;
	}

}


void printCart(const map<string, Record>& cart) {
	int item_size = 0;

	for (const auto& p : cart) {
		if (p.first.size() > item_size)
			item_size = p.first.size();
	}
	if (item_size < 14)
		item_size = 14;

	int item_pad = 10;

	cout << "Item";
	for (int i = 0; i < item_size - 4 + item_pad; i++) {
		cout << " ";
	}
	cout << "Quantity";
	for (int i = 0; i < item_size - 8 + item_pad; i++) {
		cout << " ";
	}
	cout << "Unit Price ($)";
	cout << endl;
	for (int i = 0; i < 2*item_size + 2*item_pad + 14 + item_pad; i++) {
		cout << "*";
	}
	cout << endl;

	for (const auto& p : cart) {
		cout << p.first;
		for (int i = 0; i < item_size - p.first.size() + item_pad; i++) {
			cout << " ";
		}
		cout << std::fixed << std::right << std::setw(7) << std::setprecision(0);
		cout << p.second.units;
		for (int i = 0; i < item_size - 7 + item_pad; i++) {
			cout << " ";
		}
		cout << std::fixed << std::right << std::setw(13) << std::setprecision(2);
		cout << p.second.unitPrice;
		cout << endl;
	}
	for (int i = 0; i < 2 * item_size + 2 * item_pad + 14 + item_pad; i++) {
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < 2 * item_size + item_pad + 3; i++) {
		cout << " ";
	}
	cout << "Total: ";
	vector<double> cost (cart.size());
	int i = 0;
	for (const auto& p : cart) {
		cost.at(i) = p.second.unitPrice * p.second.units;
		i++;
	}
	cout << std::fixed << std::right << std::setw(13) << std::setprecision(2);
	cout << std::accumulate(cost.begin(), cost.end(), 0.0);
	cout << endl;
}
