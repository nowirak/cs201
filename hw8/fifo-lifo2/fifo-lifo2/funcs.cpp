/**
 filename:	funcs.cpp
 author:	Nick Wirak
 date:		4/26/2021
 summary:
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
#include "Container.hpp"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;


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
