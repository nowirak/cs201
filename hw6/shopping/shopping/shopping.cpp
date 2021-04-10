/**
 filename:	shopping.cpp
 author:	Nick Wirak
 date:		4/09/2021
 summary:   Implementation of a basic shopping experience. The store inventory and pricing
            is written into the source code. A user can 'add', and  'remove' store items
            if they are available to his cart. A user can also print their cart. The 
            printout is formatted and includes a total sales amount computation and 
            printout.

*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <map>
using std::map;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;

#include "funcs.hpp"


int main()
{
    //Definition of store inventory.
    map<string, Record> inventory
    { {"toothbrush", {0.50, 60}},
        {"book", {6.00, 30}},
        {"covid mask", {0.25, 1000}},
        {"paper cup", {0.10, 1000}},
        {"light bulb", {1.00, 100}} };

    //Create cart of user.
    map<string, Record> cart;
    
    //Customer greeting and printout of items for sale from the store.
    cout << "You are at the store." << endl;
    cout << "The store currently offers:" << endl << endl;
    printInventory(inventory);
    cout << endl;

    //Printout and display program user instructions.
    cout << "Operation and Commands: " << endl;
    cout << "   " << "Type 'add'    to add items to cart." << endl;
    cout << "   " << "Type 'remove' to remove items from cart." << endl;
    cout << "   " << "Type 'cart'   to print and review cart." << endl;
    cout << "   " << "Type 'exit'   to exit the program." << endl;
    cout << endl;
   

    istringstream istream;
    string user;
    string user2;
    int quant;

    //User shopping interface loop.
    while (true) {
        //Get user command.
        cout << "command> ";
        getline(cin, user);

        //Determine if user command entry is valid, and appropriate subsequent action if
        //valid.
        if (user == "add") {
            //Get subcommand from user.
            cout << "   " << "item> ";
            getline(cin, user);
            //Determine if subcommand is valid.
            if (inventory.count(user) == 0) {
                cout << "***Error: '" << user << "' is not a valid item." << endl;
            }
            else {
                //Get additional subcommand from user.
                cout << "   " << "quantity> ";
                getline(cin, user2);
                istream.clear();
                istream.str(user2);
                istream >> quant;
                //Determine subcommand validity.
                if (!istream) {
                    cout << "***Error: " << user2 << "' is not a valid quantity to add." << endl;
                }
                else if (quant < 0) {
                    cout << "***Error: '" << quant << "' is not a valid quantity to add." << endl;
                }
                //Check if store has items in specified amount in stock.
                else if (quant > inventory[user].units) {
                    cout << "***Error: There is not enough inventory to add " << quant << " items." << endl;
                }
                //Add specified store items to user cart.
                else {
                    if (cart.count(user) == 0) {
                        cart[user].units = quant;
                    }
                    else {
                        cart[user].units += quant;
                    }
                    cart[user].unitPrice = inventory[user].unitPrice;
                    inventory[user].units -= quant;
                }
            }
            cout << endl;
        }
        else if (user == "remove") {
            //Get subcommand from user.
            cout << "   " << "item> ";
            getline(cin, user);
            //Determine if subcommand is valid.
            if (cart.count(user) == 0) {
                cout << "***Error: '" << user << "' is not an item in your cart." << endl;
            }
            else {
                //Get additional subcommand from user.
                cout << "   " << "quantity> ";
                getline(cin, user2);
                istream.clear();
                istream.str(user2);
                istream >> quant;
                //Determine subcommand validity.
                if (!istream) {
                    cout << "***Error: '" << user2 << "' is not a valid quantity to remove." << endl;
                }
                else if (quant < 0) {
                    cout << "***Error: '" << quant << "' is not a valid quantity to remove." << endl;
                }
                else if (quant > cart[user].units) {
                    cout << "***Error: You do not have enough items in your cart to remove ";
                        cout << quant << "items." << endl;
                }
                //Remove user specified items from cart.
                else {
                    cart[user].units -= quant;
                    inventory[user].units += quant;
                }
            }
            cout << endl;
            if (cart[user].units == 0) {
                cart.erase(user);
            }
        }
        //Print user cart.
        else if (user == "cart") {
            if (cart.size() == 0) {     //or can use std::advance(it, 1) to add 1 to iterator
                cout << "Your cart is empty." << endl << endl;
            }
            else {
                cout << endl;
                printCart(cart);
                cout << endl;
            }
        }
        //User exit command implementation.
        else if (user == "exit") {
            break;
        }
        else {
            cout << "***Error: '" << user << "' is not a valid command." << endl << endl;
        }
    }

   
    return 0;
}

