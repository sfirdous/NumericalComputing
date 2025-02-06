#include <iostream>
#include <cmath>
#include <iomanip>

class RootFinding
{

private:
    // Data members
    double tol;
    double start;
    double end;
    double step;

public:
    // Constructors
    RootFinding();
    RootFinding(double tol, double start, double end, double step);

    // Methods
    bool findStartingInterval(double &a, double &b);
    double findInitialGuess();

    // Root Finding Methods
    void bisection(double a, double b);
    void newtonRaphson();
    void fixedPointIteration();

    // Polynomail
    double f(double x);

    // Derivative
    double df(double x);
};