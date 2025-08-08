#include "Interpolation.hpp"
#include <cmath>


Polynomial Interpolation::exponentialFit() {
    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;

    for (int i = 0; i < n; i++) {
        double x1 = x[i];
        double y = log(fx[i]);

        sum_x += x1;
        sum_y += y;
        sum_xy += x1 * y;
        sum_x2 += x1 * x1;
    }

    double mean_x = sum_x / n;
    double mean_y = sum_y / n;

    double m = (sum_xy - n*mean_x*mean_y) / (sum_x2 - n*(mean_x * mean_x));
    double c = mean_y - m*mean_x;

    std::vector<double> r = {exp(c),m};
    Polynomial f(r);
    return f;
}