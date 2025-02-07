#include <iostream>
#include <cmath>
#include <iomanip>

class RootFinding
{
private:
    double tol;
    double start;
    double end;
    double step;

public:
    //Constructors
    RootFinding();
    RootFinding(double tol, double start, double end, double step);

    //Root Finding Methods
    double newtonRaphson();
    double fixedPointIteration();
    double bisection(double &a, double &b);

    //Polynomail's
    double f(double x);
    double df(double x);
    double g(double x);

    bool findStartingInterval(double &a, double &b);
    double findInitialGuess();
    
};
