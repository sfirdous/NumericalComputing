#include "RootFinding.hpp"

// Default Constructors
RootFinding::RootFinding()
{
    tol = 0.00001;
    start = -10;
    end = 10;
    step = 0.1;
}

// Parametrized Constructors
RootFinding::RootFinding(double tol, double start, double end, double step)
{
    this->tol = tol;
    this->start = start;
    this->end = end;
    this->step = step;
}

// Method to find starting interval for bisection
bool RootFinding::findStartingInterval(double &a, double &b)
{

    for (double x = start; x <= end; x += step)
    {
        if (f(x) * f(x + step) < 0)
        {
            a = x;
            b = x + step;
            return true;
        }
    }
    return false;
}

// Method for finding initial points for Newton Raphson and fixed point
double RootFinding::findInitialGuess()
{
    for (double x = start; x < end; x += step)
    {
        if (f(x) * f(x + step) < 0)
        {
            return (x + x + step) / 2;
        }
    }
    return start;
}

// Polynomail
double RootFinding::f(double x)
{
    return x * x  - 5*x + 5; 
}

// Derivative of Polynomial
double RootFinding::df(double x)
{
    return 2* x  - 5; 
}

//
double RootFinding::g(double x)
{
    return  (x*x + 5)/5;
}

