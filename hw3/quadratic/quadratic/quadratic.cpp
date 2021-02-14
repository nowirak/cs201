/**
 filename:	quadratic.cpp
 author:	Nick Wirak
 date:		2/9/2021
 summary:	Has limited user interaction. Parameters of ax^2+bx+c are set in source code.
            Program prints calculated roots, queries for a test error. Reports if the root
            evaluated to within test error of zero on a pass or fail basis. Reports absolute
            error from zero. Note: error is not the error of the calculated root to the real
            root, it is the distance of the function evaluated at the calculated root from 
            zero.
*/

#include <iostream>
#include <vector>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

//Computes root of equation of the form ax^2+bx+c. For first root, set n = 1. For
//second root, set n = -1.
inline double root(const double& a, const double& b, const double& c, const int& n) {
    return (-1 * b + n * sqrt(b * b - 4 * a * c)) / (2 * a);
}

//Prints roots of equation of the form ax^2+bx+c. If no positive roots exist, a report
//to that end is printed instead.
inline void printRoots(const double& a, const double& b, const double& c) {
    if (b * b - 4 * a * c < 0) {
        cout << "there are no real roots..." << endl;
    }
    else
        cout << "roots: " << root(a,b,c,1) << " , " << root (a,b,c,-1) << endl;
}

//Evaluates ax^2+bx+c at the chosen root. Choose roots with n = 1 or -1.
inline double test(const double& a, const double& b, const double& c, const int& n) {
    double root = root(a, b, c, n);
    return a* root* root + b * root + c;
}

int main()
{
    int a, b, c;
    double error;

    a = 1;
    b = -5;
    c = 5;

    printRoots(a, b, c);    //print roots

    cout << endl;

    cout << "desired test error: ";
    cin >> error;   //set test error
    cout << endl;

    //test pass/fail notification by root
    if (abs(test(a,b,c,1)) < error)
        cout << "root 1 test: pass" << endl;
    else
        cout << "root 1 test: fail" << endl;

    if (abs(test(a,b,c,-1)) < error)
        cout << "root 2 test: pass" << endl;
    else
        cout << "root 2 test: fail" << endl;

    cout << endl;

    //report of actual test error
    cout << "root 1 error: " << abs(test(a,b,c,1)) << endl;
    cout << "root 2 error: " << abs(test(a,b,c,-1)) << endl;

    return 0;
}

