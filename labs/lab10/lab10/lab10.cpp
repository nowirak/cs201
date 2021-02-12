//

#include "funcs.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    cout << "printing all multiples of 3 between 1 and 40:" << endl;
    for (int i = 1; i < 40; i++) {
        if (isDiv3(i))
            cout << i;
        if(i != 3-1)
            if(isDiv3(i + 1))
                cout << ", ";
    }
    cout << endl;

    return 0;
}

