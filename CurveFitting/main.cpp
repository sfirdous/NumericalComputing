#include <iostream>
#include <iomanip>
#include "CurveFit.hpp"

using namespace std;

int main() {

    CurveFit cf("/workspaces/NumericalComputing/CurveFitting/data/example1.txt");


    // Test Linear Fit
    long double a, b;
    cf.linearLeastSquaresFit(a, b);
    cout << a << b << endl;

    long double qa, qb, qc;
    cf.quadraticLeastSquaresFit(qa, qb, qc);
    cout << qa << qb << qc << endl;

    // Test Exponential Fit
    long double ae, be;
    cf.exponentialFit(ae, be);
    cout << ae <<  be <<  << endl;

   
    long double ap, bp;
    cf.powerFit(ap, bp);
    cout << ap << bp << endl;

    return 0;
}
