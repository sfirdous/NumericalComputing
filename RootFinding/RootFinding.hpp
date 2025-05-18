#ifndef ROOTFIND_HPP
#define ROOTFIND_HPP

#include <iostream>
#include <cmath>
#include "../Polynomial/Polynomial.hpp"

class RootFinding
{
private:
    double tol;
    double start;
    double step;
    double end;

public:
    RootFinding();
    RootFinding(double tol, double start, double step, double end);

    double bisection(Polynomial& fx);
    double newtonRaphson(Polynomial& fx);
    double fixedPoint(Polynomial &fx,Polynomial& gx,double power = 1,double denom = 1.0);

    bool findStartingInterval(double &a, double &b,Polynomial& fx);
    double initialGuess(Polynomial& fx);
};
#endif