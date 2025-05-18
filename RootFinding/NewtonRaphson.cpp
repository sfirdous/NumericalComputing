#include "RootFinding.hpp"
using namespace std;


double RootFinding::newtonRaphson(Polynomial &fx)
{
    double x0 = initialGuess(fx);
    int iteration = 0;
    Polynomial dfx = fx.derivative();
    double x_new = 0.0; 
    while (true)
    {
        double f_x = fx.evaluate(x0);
        double df_x = dfx.evaluate(x0);

        if (df_x < tol)
        {
            cout << "Derivative too small. Method failed.\n";
            return -1.0;
        }

        x_new = x0 - (f_x / df_x);
        if((x_new - x0)  < tol)
            break;
        
        x_new = x0;
        iteration++;
    }

    return x_new;
}