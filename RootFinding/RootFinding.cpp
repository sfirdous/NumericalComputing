#include "RootFinding.hpp"
using namespace std;

RootFinding::RootFinding()
{
    tol = 1e-6;
    start = -10.0;
    step = 0.1;
    end = 10.0;
}

RootFinding::RootFinding(double tol, double start, double step, double end)
{
    this->tol = tol;
    this->start = start;
    this->step = step;
    this->end = end;
}

bool RootFinding::findStartingInterval(double& a,double& b,Polynomial& fx)
{
    for(double x = start; x <= end ; x += step)
    {
        if(fx.evaluate(x) * fx.evaluate(x+step) < 0)
        {
            a = x;
            b = x + step;
            return true;
        }
    }
    return false;
}
double RootFinding::initialGuess(Polynomial& fx)
{
    for(double x = start ; x <= end ; x += step)
    {
        if(fx.evaluate(x) * fx.evaluate(x+step) < 0)
            return (x+x+step) / 2;
    }
    return start;
}
