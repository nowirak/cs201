//
//
//

#include <iostream>
#include "modifyString.hpp"

int main()
{
    std::string stringInMain = "Hello";
    std::cout << "length: " << modifyString(0, stringInMain) << std::endl;
    std::cout << "stringInMain: " << stringInMain << std::endl << std::endl;

    std::cout << "length: " << modifyString(1, stringInMain) << std::endl;
    std::cout << "stringInMain: " << stringInMain << std::endl << std::endl;

    std::cout << "length: " << modifyString(2, stringInMain) << std::endl;
    std::cout << "stringInMain: " << stringInMain << std::endl;
}
