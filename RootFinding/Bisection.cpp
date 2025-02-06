#include "RootFinding.hpp"

void RootFinding::bisection(double a, double b)
{
    std::cout << std::fixed << std::setprecision(4); 
    if (!findStartingInterval(a, b))
    {
        std::cout << "No Interval found where f(a) * f(b)  < 0.\n";
        return;
    }
    std::cout << "Starting Interval: [" << a << ", " << b << "]\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "Iter       |       a       |       b       |       f(a)       |       f(b)       |       Mid       |       f(Mid)\n";
    std::cout << "--------------------------------------------------\n";

    int iteration = 0;
    double mid;

    while ((b - a) / 2.0 > tol)
    {
        mid = (a + b) / 2.0;
        std::cout << iteration + 1 << "       |       " << a << "      |       " << b << "       |       " << f(a) << "       |       " << f(b) << "       |       " << mid << "       |       " << f(mid) << "\n";

        if (fabs(f(mid)) < tol)
        { // If function value is within tolerance
            break;
        }

        if (f(mid) * f(a) < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }

        iteration++;
    }

    std::cout << "--------------------------------------------------\n";
    std::cout << "Approximate Root: " << mid << "\n";
    std::cout << "Total Iterations: " << iteration + 1 << "\n";
}