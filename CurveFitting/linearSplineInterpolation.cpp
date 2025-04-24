#include "CurveFit.hpp"
#include <vector>

long double CurveFit::linearSplineInterpolation(long double x)
{
    
    if (n < 2) {
        std::cout << "Need at least two data points for linear spline interpolation." << std::endl;
        return 0.0;
    }

   
    if (x < x_i[0] || x > x_i[n - 1]) {
        std::cerr << "x is out of the interpolation range." << std::endl;
        return 0.0;
    }

    //interval where x belongs
    int i = 0;
    while (i < n - 1 && x > x_i[i + 1]) {
        ++i;
    }

    // slope m_i for the interval [i, i+1]
    long double m_i = (f_x_i[i + 1] - f_x_i[i]) / (x_i[i + 1] - x_i[i]);

    // linear interpolation result point slope formula
    return f_x_i[i] + m_i * (x - x_i[i]);
}

