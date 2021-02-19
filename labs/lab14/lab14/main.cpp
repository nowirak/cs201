
#include "funcs.hpp"
#include <iostream>

int main()
{
    std::string input;

    std::cout << "Input a word: ";
    std::cin >> input;
    std::cout << std::endl;

    printStr(input);

    return 0;
}

