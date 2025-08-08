#include "Interpolation.hpp"
#include <cmath>

Polynomial Interpolation::powerFit() {
    double sum_logx = 0, sum_logy = 0, sum_logx2 = 0, sum_logx_logy = 0;

    for (int i = 0; i < n; i++) {
        double logx = log(x[i]);
        double logy = log(fx[i]);

        sum_logx += logx;
        sum_logy += logy;
        sum_logx2 += logx * logx;
        sum_logx_logy += logx * logy;
    }

    double mean_x = sum_logx / n;
    double mean_y = sum_logy / n;

    double m = (sum_logx_logy - n *mean_x*mean_y) / (sum_logx2 - n*(mean_x * mean_x));
    double c = mean_y - m*mean_x;

    std::vector<double> r = {exp(c),exp(m)};
    Polynomial f(r);
    return f;
}
