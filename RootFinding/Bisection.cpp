#include "RootFinding.hpp"
#include <cmath>
#include <iomanip>

#define START -10 
#define END 10 
#define STEP 0.1

double f(double x){
    return x * x * x - 4 * x - 9; // Example: f(x) = x³ - 4x - 9
}

bool findStartingInterval(double &a,double &b)
{
    double start = -10;
    double end = 10;
    double step = 0.1;
    for (double x = start; x <= end; x += step) {
        if (f(x) * f(x + step) < 0) { // Change in sign means root exists
            a = x;
            b = x + step;
            return true;
        }
    }
    return false; 

    return false;
}

void RootFinding::bisection(double a, double b)
{
    std::cout << std::fixed << std::setprecision(4); // Set decimal precision for all floating-point output
    if(!findStartingInterval(a,b)){
        std::cout << "No Interval found where f(a) * f(b)  < 0.\n";
        return;
    }
    std::cout << "Starting Interval: [" << a << ", " << b << "]\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "Iter       |       a       |       b       |       f(a)       |       f(b)       |       Mid       |       f(Mid)\n";
    std::cout << "--------------------------------------------------\n";

    int iteration = 0;
    double mid;

    while ((b - a) / 2.0 > tol) {
        mid = (a + b) / 2.0;
        std::cout << iteration+1 <<"       |       " << a << "      |       " <<b<<"       |       " << f(a)<<"       |       " << f(b)<<"       |       " <<mid<<"       |       " <<f(mid)<<"\n";

        if (fabs(f(mid)) < tol) { // If function value is within tolerance
            break;
        }

        if (f(mid) * f(a) < 0) {
            b = mid;
        } else {
            a = mid;
        }

        iteration++;
    }

    std::cout << "--------------------------------------------------\n";
    std::cout << "Approximate Root: " << mid << "\n";
    std::cout << "Total Iterations: " << iteration + 1 << "\n";
}