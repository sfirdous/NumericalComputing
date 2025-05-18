#include "CurveFit.hpp"
#include <vector>


long double CurveFit::quadraticSplineInterpolation(long double x)
{
    if (n < 2) {
        std::cout << "Need at least two data points for quadratic spline interpolation." << std::endl;
        return 0.0;
    }

    std::vector<long double> a(n - 1), b(n - 1), c(n - 1);

    //coefficients for the quadratic splines
    for (int i = 1; i < n - 1; ++i) {
        a[i] = (f_x_i[i + 1] - f_x_i[i]);                    // Forward difference
        b[i] = (x_i[i + 1] - x_i[i]);                        // Forward interval
        c[i] = (f_x_i[i] - f_x_i[i - 1]) / (x_i[i] - x_i[i - 1]); // Backward slope
    }

    // Find the interval for x
    int i = 0;
    while (i < n - 1 && x > x_i[i + 1])
        ++i;

    // Evaluate the spline at point x
    long double dx = x - x_i[i];
    long double spline_val = a[i] * dx * dx + b[i] * dx + c[i];

    return spline_val;
}
