#include "RootFinding.hpp"
using namespace std;

double RootFinding::bisection(double &a, double &b)
{
    cout << fixed << setprecision(6);

    if (!findStartingInterval(a, b))
    {
        cout << "No valid interval found where f(a) * f(b) < 0. Try a different range.\n";
        return -1;
    }


    cout << "Starting Interval: [" << a << ", " << b << "]\n";
    cout << "--------------------------------------------------\n";
    cout << "Iter  |    a       |    b       |    Mid       |   f(Mid)    \n";
    cout << "--------------------------------------------------\n";

    int iteration = 0;
    double mid;

    while ((b - a) / 2.0 > tol) 
    {
        mid = (a + b) / 2.0;
        cout << iteration + 1 << "     | " << a << "  | " << b << "  | " << mid << "  | " << f(mid) << "\n";

        if (fabs(f(mid)) < tol)
        { 
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

    cout << "--------------------------------------------------\n";
    cout << "Bisection Root Approximation: " << mid << "\n";
    cout << "Total Iterations: " << iteration + 1 << "\n";

    return mid;
}
