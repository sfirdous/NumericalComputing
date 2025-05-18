#include "CurveFit.hpp"

Polynomial CurveFit::quadraticLeastSquaresFit()
{
    double Sx4 = 0, Sx3 = 0, Sx2 = 0, Sx = 0, Sy = 0, Sxy = 0, Sx2y = 0;
    for (int i = 0; i < n; ++i)
    {
        Sx4 += pow(x[i], 4);
        Sx3 += pow(x[i], 3);
        Sx2 += pow(x[i], 2);
        Sx += x[i];
        Sy += fx[i];
        Sxy += x[i] * fx[i];
        Sx2y += fx[i] * pow(x[i], 2);
    }

    double DetD =
        Sx4 * (Sx2 * n - Sx * Sx) -
        Sx3 * (Sx3 * n - Sx2 * Sx) +
        Sx2 * (Sx3 * Sx - Sx2 * Sx2);
    
    double Detd0 =
        Sx2y * (Sx2 * n - Sx * Sx) -
        Sxy * (Sx3 * n - Sx * Sx2) +
        Sy * (Sx3 * Sx - Sx2 * Sx2);
    
    double Detd1 =
        Sx4 * (Sxy * n - Sy * Sx) -
        Sx2y * (Sx3 * n - Sx2 * Sx) +
        Sx2 * (Sx3 * Sy - Sxy * Sx2);
    
    double Detd2 =
        Sx4 * (Sx2 * Sy - Sx * Sxy) -
        Sx3 * (Sx3 * Sy - Sx * Sx2y) +
        Sx2 * (Sx3 * Sxy - Sx2 * Sx2y);

    std::vector<double> coeff = {Detd2/DetD , Detd1/DetD, Detd0/DetD};
    Polynomial result(coeff);
    return result;

}
