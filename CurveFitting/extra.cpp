#include "CurveFit.hpp"

void CurveFit::quadraticLeastSquaresFit() {
    long double Sx = 0, Sx2 = 0, Sx3 = 0, Sx4 = 0;
    long double Sy = 0, Sxy = 0, Sx2y = 0;

    for (int i = 0; i < n; i++) {
        long double x = x_i[i], y = f_x_i[i];
        Sx += x;
        Sx2 += x * x;
        Sx3 += x * x * x;
        Sx4 += x * x * x * x;
        Sy += y;
        Sxy += x * y;
        Sx2y += x * x * y;
    }


    long double D = n * (Sx2 * Sx4 - Sx3 * Sx3) - Sx * (Sx * Sx4 - Sx2 * Sx3) + Sx2 * (Sx * Sx3 - Sx2 * Sx2);
    long double Da = Sy * (Sx2 * Sx4 - Sx3 * Sx3) - Sx * (Sxy * Sx4 - Sx3 * Sx2y) + Sx2 * (Sxy * Sx3 - Sx2 * Sx2y);
    long double Db = n * (Sxy * Sx4 - Sx3 * Sx2y) - Sy * (Sx * Sx4 - Sx2 * Sx3) + Sx2 * (Sx * Sx2y - Sxy * Sx2);
    long double Dc = n * (Sx2 * Sx2y - Sxy * Sx3) - Sx * (Sx * Sx2y - Sxy * Sx2) + Sy * (Sx * Sx3 - Sx2 * Sx2);

    resultstruct.a = Da / D;
    resultstruct.b = Db / D;
    resultstruct.c = Dc / D;
}