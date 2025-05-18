#include"RootFinding.hpp"
using namespace std;

double RootFinding::fixedPoint(Polynomial& fx,Polynomial& gx,double power,double denom)
{
    double x0 = initialGuess(fx);
    int iteration = 0;
    double x_new = 0.0;
    do{
        x_new = pow(gx.evaluate(x0),power) / denom;
        iteration++;
        x0 = x_new;
    }while(fabs(x_new - x0) > tol);

    return x_new;
}