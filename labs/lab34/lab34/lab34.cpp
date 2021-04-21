// printtime.cpp  INCOMPLETE
// Glenn G. Chappell
// 20 Apr 2018
//
// For CS 201 Spring 2018
// Time of Day Class & Program
//
// Modified 11/28/18 for CS 201 Fall 2018
// Chris Hartman

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iomanip>
using std::setfill;
using std::setw;



// Class Time
// Holds a time of day: hours, minutes, seconds. Can print its stored
// time in a nice format.
class Time {

public:
    // ***** Time: constructors *****

        // TODO: Put something here!

    Time() : _hr(1), _min(2), _sec(3) {}

    // ***** Time: general public member functions *****

    void print() const
    {
        //cout << "SOMETHING NEEDS TO GO HERE";  // DUMMY
        // TODO: Write this!
        cout << setfill('0') << setw(2) << _hr << ":";
        cout << setfill('0') << setw(2) << _min << ":";
        cout << setfill('0') << setw(2) << _sec;
    }

    // ***** Time: data members *****
private:

    int _hr;   // Hours past midnight
    int _min;  // Minutes past the hour
    int _sec;  // Seconds past the minute

};  // End class Time


int main()
{
    // Print header
    cout << "Here are some times:" << endl;
    cout << endl;

    // Make a Time object; print it
    Time t1;
    cout << "Time #1: [";
    t1.print();
    cout << "]" << endl;
    cout << endl;

    // Wait for user
    cout << "PRESS ENTER to quit ";
    while (cin.get() != '\n');
}
