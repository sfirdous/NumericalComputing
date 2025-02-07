#include "RootFinding.hpp"
using namespace std;

double RootFinding::fixedPointIteration()
{
    double x0 = findInitialGuess(); 
    cout << fixed << setprecision(6);
    cout << "Iter |    x        |   f(x)     \n";
    cout << "--------------------------------------------\n";

    double x_new;
    int iter = 0;

    do
    {
        x_new = g(x0);
        cout << iter << "\t  "<< x_new << "\t  " << f(x_new) << endl;

        iter = iter + 1;

        x0 = x_new;

    } while (fabs(f(x_new)) > tol);

    cout << "--------------------------------------------\n";
    cout << "Fixed Point Approximation: " << x_new << " (after " << iter << " iterations)\n";

    return x_new;
}
