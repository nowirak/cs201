
// shopping.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <map>
using std::map;
#include <string>
using std::string;
#include <algorithm>

#include "funcs.hpp"


int main()
{
    map<string, Record> inventory
    { {"toothbrush", {0.50, 60}},
        {"book", {6.00, 30}},
        {"covid mask", {0.25, 1000}},
        {"paper cup", {0.10, 1000}},
        {"light bulb", {1.00, 100}} };

    map<string, Record> cart;
    
    cout << "You are at the store." << endl;
    cout << "The store currently offers:" << endl << endl;
    printInventory(inventory);
    cout << endl;

    cout << "Operation and Commands: " << endl;
    cout << "   " << "Type 'add'    to add items to cart." << endl;
    cout << "   " << "Type 'remove' to remove items from cart." << endl;
    cout << "   " << "Type 'cart'   to print and review cart." << endl;
    cout << "   " << "Type 'exit'   to exit the program." << endl;

    cout << endl;
    
    string user;
    int quant;
    //map<string, Record>::iterator it;
    while (true) {
        cout << "command> ";
        cin >> user;
        if (user == "add") {
            cout << "   " << "item> ";
            cin >> user;
            if (inventory.count(user) == 0) {
                cout << "***Error: '" << user << "' is not a valid item." << endl;
            }
            else {
                cout << "   " << "quantity> ";
                cin >> quant;
                if (quant < 0) {
                    cout << "***Error: '" << quant << "' is not a valid quantity to add." << endl;
                }
                else if (quant > inventory[user].units) {
                    cout << "***Error: There is not enough inventory to add " << quant << endl;
                }
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
            cout << "   " << "item> ";
            cin >> user;
            if (cart.count(user) == 0) {
                cout << "***Error: '" << user << "' is not an item in your cart." << endl;
            }
            else {
                cout << "   " << "quantity> ";
                cin >> quant;
                if (quant < 0) {
                    cout << "***Error: '" << quant << "' is not a valid quantity to remove." << endl;
                }
                else if (quant > cart[user].units) {
                    cout << "***Error: You do not have enough items in your cart to remove ";
                        cout << quant << "items." << endl;
                }
                else {
                    cart[user].units -= quant;
                    inventory[user].units += quant;
                }
            }
            cout << endl;
        }
        else if (user == "cart") {
            if (cart.begin()++ == cart.end()) {     //or can use std::advance(it, 1) to add 1 to iterator
                cout << "Your cart is empty." << endl;
            }
            else {
                cout << endl;
                printCart(cart);
                cout << endl;
            }
        }
        else if (user == "exit") {
            break;
        }
        else {
            cout << "***Error: '" << user << "' is not a valid command." << endl << endl;
        }
    }

   
    return 0;
}

