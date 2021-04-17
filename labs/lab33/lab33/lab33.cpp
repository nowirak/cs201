// lab33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;

class Thing {
public:    
	Thing() :   _data1(0),
		        _data2(0)
	{}
    void printSomething() {
        cout << "Printing something." << endl;
    }
    void data1Setter(int data) {
        _data1 = data;
    }
    void data2Setter(char data) {
        _data2 = data;
    }
    int data1Getter() {
        return _data1;
    }
    char data2Getter() {
        return _data2;
    }
    void toString() {
        cout << "1st data member: " << _data1 << endl;
        cout << "2nd data member: " << _data2 << endl;
    }

private:
    int _data1;
    char _data2;
};

int main()
{
    Thing thing1;
    Thing thing2;
    thing1.printSomething();

    thing1.data1Setter(1);
    thing1.data2Setter('a');
    thing2.data1Setter(2);
    thing2.data2Setter('b');

    cout << endl;
    cout << thing1.data1Getter() << endl;
    cout << thing1.data2Getter() << endl;
    cout << thing2.data1Getter() << endl;
    cout << thing2.data2Getter() << endl;

    cout << endl;
    thing1.toString();
    cout << endl;
    thing2.toString();

    return 0;
}


