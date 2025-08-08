#include "Interpolation.hpp"
#include <vector>

double Interpolation::linearSplineInterpolation(double a)
{
    
    if (n < 2) {
        std::cout << "Need at least two data points for linear spline interpolation." << std::endl;
        return 0.0;
    }

   
    if (a < x[0] || a > x[n - 1]) {
        std::cerr << "x is out of the interpolation range." << std::endl;
        return 0.0;
    }

    //interval where x belongs
    int i = 0;
    while (i < n - 1 && a > x[i + 1]) {
        ++i;
    }

    // slope m_i for the interval [i, i+1]
    long double m_i = (fx[i + 1] - fx[i]) / (x[i + 1] - x[i]);

    // linear interpolation result point slope formula
    return fx[i] + m_i * (a - x[i]);
}

