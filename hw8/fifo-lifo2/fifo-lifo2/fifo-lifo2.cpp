/**
 filename:	fifo-lifo2.cpp
 author:	Nick Wirak
 date:		4/26/2021
 summary:	The user is given a vector as a container to push and pop strings
            from. The user can switch between fifo and lifo modes at any time,
            and this will affect which vector element is popped. The user can print
            their container at any time, and test the functionality of the built-in
            fifo an lifo modes of operation at any time.
*/

#include "funcs.hpp"
#include "Container.hpp"
#include <iostream>
using namespace std;

int main()
{
    //Program and user instructions outline printout.
    cout << "You have a container, and can push and pop strings to/from it." << endl
        << endl;
    cout << "Commands (input without colon):" << endl;
    cout << "   fifo:          Select and the fifo routine. Lifo is default." << endl;
    cout << "   lifo:          Select and the lifo routine. Lifo is default." << endl;
    cout << "   push \"string\": Push a string to the container (put string inside"
        << endl;
    cout << "                  quotes, one space after push, nothing after last quote)."
        << endl;
    cout << "   pop:           Pop a string from the container and print." << endl;
    cout << "   print:         Print the container." << endl;
    cout << "   test:          Run a test of the validity of fifo and lifo functionality."
        << endl;
    cout << "   exit:          Quit the program." << endl << endl;

    string input = "start";
    Container container;
    bool fifoLifo = true;       // false = fifo mode , true = lifo mode

    do {
        cout << "input: ";      //Acquire user instruction.
        getline(cin, input);

        //Read and decipher instructions, acting accordingly.
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
        else if (input.size() >= 7 && input.substr(0, 6) == "push \"" &&
            input.back() == '"') {
            if (fifoLifo == false) {
                container.fifoPush(input.substr(6, input.size() - 7));
            }
            else {
                container.lifoPush(input.substr(6, input.size() - 7));
            }
            cout << "*data pushed" << endl;
            continue;
        }
        else if (input == "pop") {
            if (container.isContainerEmpty()) {
                cout << "***Error. The container is empty." << endl;
            }
            else {
                if (fifoLifo == false) {
                    container.fifoPop(input);
                }
                else {
                    container.lifoPop(input);
                }
                cout << "data popped" << endl;
            }
            continue;
        }
        else if (input == "print") {
            if (container.isContainerEmpty()) {
                cout << "***The container is empty." << endl;
            }
            else {
                container.printContainer();
                cout << endl;
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

