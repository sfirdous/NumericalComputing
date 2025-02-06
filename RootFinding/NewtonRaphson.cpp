#include "RootFinding.hpp"
using namespace std;

void RootFinding::newtonRaphson()
{
    double x0 = findInitialGuess(); // Initial guess
    cout << fixed << setprecision(4); // Set decimal precision to 6 places
    cout << "Iter |    x        |   f(x)      |   f'(x)     |   x_new     |  Diff  \n";
    cout << "------------------------------------------------------------------------\n";

    double x_new;
    int iteration = 0;

    while (true)
    {
        double fx = f(x0);
        double dfx = df(x0);

        if (fabs(dfx) < 1e-6)
        { // Avoid division by zero
            cout << "Derivative too small. Method failed.\n";
            return;
        }

        x_new = x0 - (fx / dfx);        // Newton-Raphson formula
        double diff = fabs(x_new - x0); // Compute difference between iterations

        cout << iteration + 1 << "    | " << x0 << "  | " << fx << "  | "
             << dfx << "  | " << x_new << "  | " << diff << "\n";

        if (diff < tol)
        { // Stop when difference is less than tolerance
            break;
        }

        x0 = x_new;
        iteration++;
    }

    cout << "------------------------------------------------------------------------\n";
    cout << "Root Approximation: " << x_new << " (after " << iteration + 1 << " iterations)\n";
}
