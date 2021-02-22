// fifo-lifo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "funcs.hpp"
#include <iostream>
using namespace std;

int main()
{
    cout << "You have a container, and can push and pop strings to/from it." << endl << endl;
    cout << "Commands:" << endl;
    cout << "   fifo:          Select and the fifo routine. Lifo is default." << endl;
    cout << "   lifo:          Select and the lifo routine. Lifo is default." << endl;
    cout << "   push \"string\": Push a string to the container (put string inside" << endl;
    cout << "                  quotes, one space after push, nothing after last quote)." << endl;
    cout << "   pop:           Pop a string from the container and print." << endl;
    cout << "   print:         Print the container." << endl;
    cout << "   test:          Run a test of the validity of fifo and lifo functionality." << endl;
    cout << "   exit:          Quit the program." << endl << endl;

    string input = "start";
    vector<string> container(0);
    bool fifoLifo = true;       // false = fifo mode , true = lifo mode
    
    do {
        cout << "input: ";
        getline(cin, input);

        if (input == "fifo") {
            fifoLifo = false;
            cout << "*fifo function" << endl;
            continue;
        }
        else if (input == "lifo") {
            fifoLifo = true;
            cout << "*lifo function" << endl;
            continue;
        }
        else if (input.size() >= 7 && input.substr(0, 6) == "push \"" && input.back() == '"') {
            if (fifoLifo == false) {
                FifoPush(container, input.substr(6, input.size() - 7));
            }
            else {
                LifoPush(container, input.substr(6, input.size() - 7));
            }
            cout << "*data pushed" << endl;
            continue;
        }
        else if (input == "pop") {
            if (IsContainerEmpty(container)) {
                cout << "***Error. The container is empty." << endl;
            }
            else {
                if (fifoLifo == false) {
                    FifoPop(container, input);
                }
                else {
                    LifoPop(container, input);
                }
                cout << "data popped" << endl;
            }
            continue;
        }
        else if (input == "print") {
            if (IsContainerEmpty(container)) {
                cout << "***The container is empty." << endl;
            }
            else {
                cout << endl;
                PrintContainer(container);
                cout << endl << endl;
            }
            continue;
        }
        else if (input == "test") {
            cout << "fifo test result: ";
            if (TestFifo() == 1) {
                cout << "pass" << endl;
            }
            else {
                cout << "*fail" << endl;
            }
            cout << "lifo test result: ";
            if (TestLifo() == 1) {
                cout << "pass" << endl;
            }
            else {
                cout << "*fail" << endl;
            }
            continue;
        }
        else if (input == "exit") {
            break;
        }
        else {
            cout << "***Please enter a valid input." << endl;
            continue;
        }

    } while (input != "exit");

    return 0;
}

