#include "RootFinding.hpp"
using namespace std;


double RootFinding::bisection(Polynomial& fx)
{
    double a = 0.0;
    double b = 0.0;

    if(!findStartingInterval(a,b,fx))
    {
        cout << "No valid interval found where f(a) * f(b) < 0. Try a different range.\n";
        return -1;
    }

    double mid;
    int iteration  = 0;

    while((b-a) / 2 > tol)
    {
        mid = (a+b) / 2;

        if(fabs(fx.evaluate(mid)) < tol)
            break;
        
        if(fx.evaluate(mid) * fx.evaluate(a) < 0)
            b = mid;
        else
            a = mid;
        
        iteration++;
    }
    return mid;
}