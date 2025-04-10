#include "CurveFit.hpp"
#include <cmath>

// Exponential Fit: f(x) = ae^(bx)
void CurveFit::exponentialFit(long double &a, long double &b) {
    long double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;

    for (int i = 0; i < n; i++) {
        long double x = x_i[i];
        long double y = log(f_x_i[i]);

        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_x2 += x * x;
    }

    long double denom = n * sum_x2 - sum_x * sum_x;
    b = (n * sum_xy - sum_x * sum_y) / denom;
    long double A = (sum_y * sum_x2 - sum_x * sum_xy) / denom;

    a = exp(A);
}