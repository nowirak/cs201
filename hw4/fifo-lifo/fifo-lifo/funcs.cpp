
#include "funcs.hpp"
#include <iostream>
using std::cout;
using std::endl;

void FifoPush(vector<string>& container, const string& item) {
	container.push_back(item);
	return;
}

void FifoPop(vector<string>& container, string& item) {
	item = container.at(0);
	for (int i = 0; i < container.size() - 1; i++) {
		container.at(i) = container.at(i + 1);

	}
	container.resize(container.size() - 1);
}

void LifoPush(vector<string>& container, const string& item) {
	container.push_back(item);
	return;
}

void LifoPop(vector<string>& container, string& item) {
	item = container.back();
	container.pop_back();
	return;
}

bool IsContainerEmpty(const vector<string>& container) {
	return container.size() == 0;
}

void PrintContainer(const vector<string>& container) {
	for (int i = 0; i < container.size() - 1; i++) {
		cout << container.at(i) << endl;
	}
	cout << container.at(container.size() - 1);
}

bool TestFifo() {
	vector<string> testPushSeq{ "push \"A\"", "push \"B\"", "push \"C\"", "push \"D\"" };
	vector<string> testPopSeq{ "pop", "pop", "pop", "pop" };
	vector<string> correctReturn{ "A", "B", "C", "D" };
	vector<string> storage;
	vector<string> returnSeq;

	for (int i = 0; i < 4; i++) {
		if (testPushSeq.at(i).size() >= 7 && testPushSeq.at(i).substr(0, 6) == "push \"" && testPushSeq.at(i).back() == '"') {
			FifoPush(storage, testPushSeq.at(i).substr(6, testPushSeq.at(i).size() - 7));
		}
		else {
			return 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (testPopSeq.at(i) == "pop") {
			returnSeq.resize(i + 1);
			FifoPop(storage, returnSeq.at(i));
		}
		else {
			return 0;
		}
	}

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
	vector<string> storage;
	vector<string> returnSeq;

	for (int i = 0; i < 4; i++) {
		if (testPushSeq.at(i).size() >= 7 && testPushSeq.at(i).substr(0, 6) == "push \"" && testPushSeq.at(i).back() == '"') {
			LifoPush(storage, testPushSeq.at(i).substr(6, testPushSeq.at(i).size() - 7));
		}
		else {
			return 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (testPopSeq.at(i) == "pop") {
			returnSeq.resize(i + 1);
			LifoPop(storage, returnSeq.at(i));
		}
		else {
			return 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (returnSeq.at(i) != correctReturn.at(i))
			return 0;
		else
			return 1;
	}
}

int readCommand(const string& command) {
	if (command == "pop") {
		return 2;
	}
	else if (command.size() >= 7 && command.substr(0, 6) == "push \"" && command.back() == '"') {
		return 1;
	}
	else {
		return 0;
	}
}