#include "CurveFit.hpp"

// Linear Least Squares Fit: f(x) = ax + b
void CurveFit::linearLeastSquaresFit(long double &a, long double &b) {
    long double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for (int i = 0; i < n; i++) {
        sum_x += x_i[i];
        sum_y += f_x_i[i];
        sum_xy += x_i[i] * f_x_i[i];
        sum_x2 += x_i[i] * x_i[i];
    }

    long double denom = n * sum_x2 - sum_x * sum_x;
    a = (n * sum_xy - sum_x * sum_y) / denom;
    b = (sum_y * sum_x2 - sum_x * sum_xy) / denom;
}