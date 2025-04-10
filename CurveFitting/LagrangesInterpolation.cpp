#include "CurveFit.hpp"

// Lagrange's Interpolation
long double CurveFit::lagrangesInterpolation(long double a) {
    long double result = 0;

    for (int i = 0; i < n; i++) {
        long double term = f_x_i[i];
        for (int j = 0; j < n; j++) {
            if (j != i)
                term *= (a - x_i[j]) / (x_i[i] - x_i[j]);
        }
        result += term;
    }

    return result;
}