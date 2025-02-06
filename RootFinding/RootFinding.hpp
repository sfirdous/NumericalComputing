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
    RootFinding();
    RootFinding(double tol, double start, double end, double step);
    bool findStartingInterval(double &a, double &b);
    double findInitialGuess();
    double f(double x);
    double df(double x);
    double g(double x);
    double dg(double x);
    void newtonRaphson();
    void fixedPointIteration();
    void bisection(double& a, double& b);






};