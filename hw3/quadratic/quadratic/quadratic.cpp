// quadratic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

inline double root(const double& a, const double& b, const double& c, const int& n) {
    return (-1 * b + n * sqrt(b * b - 4 * a * c)) / (2 * a);
}

inline void printRoots(const double& a, const double& b, const double& c) {
    if (b * b - 4 * a * c < 0) {
        cout << "there are no real roots..." << endl;
    }
    else
        cout << "roots: " << root(a,b,c,1) << " , " << root (a,b,c,-1) << endl;
}

inline double test(const double& a, const double& b, const double& c, double root) {
    return a* root* root + b * root + c;
}

int main()
{
    int a, b, c;
    double error;

    a = 1;
    b = -5;
    c = 5;

    printRoots(a, b, c);

    cout << endl;

    cout << "test error: ";
    cin >> error;
    cout << endl;

    if (abs(test(a, b, c, root(a, b, c, 1))) < error)
        cout << "root 1 test: pass" << endl;
    else
        cout << "root 1 test: fail" << endl;

    if (abs(test(a, b, c, root(a, b, c, -1))) < error)
        cout << "root 2 test: pass" << endl;
    else
        cout << "root 2 test: fail" << endl;

    cout << endl;

    cout << "root 1 error: " << test(a,b,c,root(a,b,c,1)) << endl;
    cout << "root 2 error: " << test(a, b, c, root(a, b, c, -1)) << endl;

    return 0;
}

