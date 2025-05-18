#include "CurveFit.hpp"
Polynomial CurveFit::linearLeastSquaresFit() {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += fx[i];
        sum_xy += x[i] * fx[i];
        sum_x2 += x[i] * x[i];
    }

    double mean_x = sum_x / n;
    double mean_y = sum_y / n;

    double m = (sum_xy - n*mean_x*mean_y) / (sum_x2 - n*(mean_x * mean_x));
    double c = mean_y - m*mean_x;

    std::vector<double> r = {c,m};
    Polynomial f(r);
    return f;
    
}