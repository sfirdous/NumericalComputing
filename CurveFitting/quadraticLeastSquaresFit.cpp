#include "CurveFit.hpp"

void CurveFit::quadraticLeastSquaresFit() {
    long double S_x = 0, S_x2 = 0, S_x3 = 0, S_x4 = 0;
    long double S_y = 0, S_xy = 0, S_x2y = 0;

    // Summing up required terms
    for (int i = 0; i < n; ++i) {
        long double x = x_i[i];
        long double y = f_x_i[i];
        S_x += x;
        S_x2 += x * x;
        S_x3 += x * x * x;
        S_x4 += x * x * x * x;
        S_y += y;
        S_xy += x * y;
        S_x2y += x * x * y;
    }

    // Compute determinant of coefficient matrix A
    long double detA = 
        S_x4 * (S_x2 * n - S_x * S_x) -
        S_x3 * (S_x3 * n - S_x * S_x2) +
        S_x2 * (S_x3 * S_x - S_x2 * S_x2);

    // Compute determinant of matrix A2 (replace first column with constants)
    long double detA2 = 
        S_x2y * (S_x2 * n - S_x * S_x) -
        S_xy  * (S_x3 * n - S_x * S_x2) +
        S_y   * (S_x3 * S_x - S_x2 * S_x2);

    // Compute determinant of matrix A1 (replace second column with constants)
    long double detA1 = 
        S_x4 * (S_xy * n - S_y * S_x) -
        S_x2y * (S_x3 * n - S_x * S_x2) +
        S_x2 * (S_x3 * S_y - S_xy * S_x2);

    // Compute determinant of matrix A0 (replace third column with constants)
    long double detA0 = 
        S_x4 * (S_x2 * S_y - S_x * S_xy) -
        S_x3 * (S_x3 * S_y - S_x * S_x2y) +
        S_x2 * (S_x3 * S_xy - S_x2 * S_x2y);

    // Solve for a2, a1, a0 using Cramer's Rule
    resultstruct.a = detA2 / detA;
    resultstruct.b = detA1 / detA;
    resultstruct.c = detA0 / detA;
}
