#include "RootFinding.hpp"

RootFinding::RootFinding()
{
    tol = 0.00001;
    start = -10;
    end = 10;
    step = 0.1;
}

RootFinding::RootFinding(double tol, double start, double end, double step)
{
    this->tol = tol;
    this->start = start;
    this->end = end;
    this->step = step;
}

bool RootFinding::findStartingInterval(double &a,double &b)
{
  
    for (double x = start; x <= end; x += step) {
        if (f(x) * f(x + step) < 0) 
        { 
            a = x;
            b = x + step;
            return true;
        }
    }
    return false; 

}


double RootFinding::findInitialGuess(double start, double end, double step) {
    for (double x = start; x < end; x += step) {
        if (f(x) * f(x + step) < 0) { 
            return (x + x + step) / 2; 
        }
    }
    return start; 
}


double RootFinding::f(double x){
    return x * x * x - 4 * x - 9; // f(x) = x³ - 4x - 9
}

double RootFinding::df(double x) {
    return 3 * x * x - 4; // Derivative: f'(x) = 3x² - 4
}