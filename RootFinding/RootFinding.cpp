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

// Method for finding initial points for newton raphson and fixed point
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
    return x * x * x - 4 * x - 9; // f(x) = x³ - 4x - 9
}

// Derivative of Polynomail
double RootFinding::df(double x)
{
    return 3 * x * x - 4; // Derivative: f'(x) = 3x² - 4
}

//
double RootFinding::g(double x)
{
    return  (4*x + 9)/3;
}

double RootFinding::dg(double x)
{
   return 4/3;
}