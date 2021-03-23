// lookup.cpp  INCOMPLETE
// Glenn G. Chappell
// 21 Mar 2018
//
// For CS 201 Spring 2018
// Look-up by Key, Improved
//
// Modified 10/26/18
// Chris Hartman
// For CS 201 Fall 2018

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <utility>
using std::pair;
using std::make_pair;
#include <cstdlib>
using std::size_t;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;


// sequentialSearch
// Given a vector<pair<int, string>> holding key-value pairs, and a key
// to search for (thekey). Does Sequential Search in an attempt to find
// the given key. If it is not found, returns pair containing false and
// an arbitrary number. If it is found, returns a pair containing true
// and the index at which the key was found.
pair<bool, size_t>
sequentialSearch(const vector<pair<int, string>> kvpairs,
    int thekey)
{

    for (size_t i = 0; i < kvpairs.size(); i++) {
        if (kvpairs.at(i).first == thekey)
            return { true, i };
    }

    return { false, 0 };  // DUMMY
     // TODO: Write this!
}


// Main program
// Create a dataset, and do searches in it.
int main()
{
    // Make associative (KEY-VALUE) dataset
    vector<pair<int, string>> kvpairs{
        { 21, "Alice Smith" },
        { 22, "Bill Jones" },
        { 23, "Charles Johnson" },
        { 25, "Daphne Robertson" },
        { 27, "Egbert Williams" },
        { 31, "Fifi Phillips" },
        { 32, "George Watson" },
        { 33, "Harriet Baker" },
        { 36, "Iris Gump" },
        { 38, "Jake Hawkins" }
    };

    // Print opening message
    cout << "Sequential Search in an associative dataset" << endl;
    cout << endl;

    // Input & search loop
    while (true)
    {
        // Get a line
        cout << "Type a positive integer KEY (empty line to end): ";
        string line;
        getline(cin, line);
        if (!cin)
            return 0;
        if (line == "")
            break;

        // Get an int from the above line
        istringstream in(line);
        int thekey;
        in >> thekey;
        if (!in)
        {
            cout << "Please type a positive integer" << endl;
            cout << endl;
            continue;
        }
        if (thekey < 1)
        {
            cout << "Please type a positive integer" << endl;
            cout << endl;
            continue;
        }

        auto p = sequentialSearch(kvpairs, thekey);
        auto success = p.first;
        if (success)
        {
            auto index = p.second;
            auto kv = kvpairs[index];
            cout << "KEY found; VALUE = " << kv.second << endl;
        }
        else
        {
            cout << "KEY not found" << endl;
        }
        cout << endl;
    }
    cout << endl;

    // Quit when user hits Enter
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n');
}

