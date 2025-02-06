#include "RootFinding.hpp"

void RootFinding::newtonRaphson()
{
    double x0 = findInitialGuess();
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Iter |    x        |   f(x)      |   f'(x)     |   x_new     |  Diff  \n";
    std::cout << "------------------------------------------------------------------------\n";

    double x_new;
    int iteration = 0;

    while (true)
    {
        double fx = f(x0);
        double dfx = df(x0);

        if (fabs(dfx) < tol)
        {
            std::cout << "Derivative too small. Method failed.\n";
            return;
        }

        x_new = x0 - (fx / dfx);
        double diff = fabs(x_new - x0);

        std::cout << iteration + 1 << "    | " << x0 << "  | " << fx << "  | "
                  << dfx << "  | " << x_new << "  | " << diff << "\n";

        if (diff < tol)
        {
            break;
        }

        x0 = x_new;
        iteration++;
    }

    std::cout << "------------------------------------------------------------------------\n";
    std::cout << "Root Approximation: " << x_new << " (after " << iteration + 1 << " iterations)\n";
}
