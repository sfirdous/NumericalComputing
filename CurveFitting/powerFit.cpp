#include "CurveFit.hpp"
#include <cmath>

// Power Fit: f(x) = a * x^b
void CurveFit::powerFit(long double &a, long double &b) {
    long double sum_logx = 0, sum_logy = 0, sum_logx2 = 0, sum_logx_logy = 0;

    for (int i = 0; i < n; i++) {
        long double logx = log(x_i[i]);
        long double logy = log(f_x_i[i]);

        sum_logx += logx;
        sum_logy += logy;
        sum_logx2 += logx * logx;
        sum_logx_logy += logx * logy;
    }

    long double denom = n * sum_logx2 - sum_logx * sum_logx;
    b = (n * sum_logx_logy - sum_logx * sum_logy) / denom;
    long double A = (sum_logy - b * sum_logx) / n;

    a = exp(A);
}
