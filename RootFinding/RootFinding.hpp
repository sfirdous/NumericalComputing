#include <iostream>

class RootFinding
{
private:
    double tol;

public:
    RootFinding()
    {
        tol = 0.00001;
    }
    RootFinding(double tolerance)
    {
        tol = tolerance;
    }
    void bisection(double a, double b);
};