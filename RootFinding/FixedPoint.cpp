#include "RootFinding.hpp"
using namespace std;

void RootFinding::fixedPointIteration()
{
    double x0 = findInitialGuess(); // Initial guess
    cout << fixed << setprecision(4);
    cout << "Iter |    x        |   f(x)     |   Diff  \n";
    cout << "--------------------------------------------\n";

    double x_new;

    do
    {
        x_new = g(x0);
        cout << "Iteration-" << step << ":\t x1 = " << setw(10) << x_new << " and f(x1) = " << setw(10) << f(x_new) << endl;

        step = step + 1;

        x0 = x_new;

    } while (fabs(f(x_new)) > tol);

    cout << "--------------------------------------------\n";
    cout << "Fixed Point Approximation: " << x_new << " (after " << step << " iterations)\n";
}
