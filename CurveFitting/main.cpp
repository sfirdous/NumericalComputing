#include <iostream>
#include <iomanip>
#include "CurveFit.hpp"

using namespace std;

int main() {

    // Create CurveFit object from file
    CurveFit cf("/workspaces/NumericalComputing/CurveFitting/data/example1.txt");

    int n = cf.getN();
    cout << "Number of data points: " << n << endl;

    // Test Lagrange Interpolation
    long double x_interp;
    cout << "\nEnter x for Lagrange interpolation: ";
    cin >> x_interp;

    long double lagrange_val = cf.lagrangesInterpolation(x_interp);
    cout << fixed << setprecision(5);
    cout << "Lagrange interpolation at x = " << x_interp << " is: " << lagrange_val << endl;

    // Test Linear Fit
    long double a, b;
    cf.linearLeastSquaresFit(a, b);
    cout << "\nLinear Fit: f(x) = " << a << " * x + " << b << endl;

    // Test Quadratic Fit
    long double qa, qb, qc;
    cf.quadraticLeastSquaresFit(qa, qb, qc);
    cout << "Quadratic Fit: f(x) = " << qa << " * x^2 + " << qb << " * x + " << qc << endl;

    // Test Exponential Fit
    long double ae, be;
    cf.exponentialFit(ae, be);
    cout << "Exponential Fit: f(x) = " << ae << " * e^(" << be << " * x)" << endl;

    // Test Power Fit
    long double ap, bp;
    cf.powerFit(ap, bp);
    cout << "Power Fit: f(x) = " << ap << " * x^" << bp << endl;

    return 0;
}
