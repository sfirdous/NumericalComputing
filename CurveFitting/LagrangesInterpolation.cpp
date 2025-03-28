#include "CurveFit.hpp"
using namespace std;
long double CurveFit::lagrangesInterpolation(long double a)
{
    double result = 0.0;
    for (int i = 0; i < n; i++)
    {
        double L_i = 0;
        double L_i_numr = 1;
        double L_i_denr = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                L_i_numr *= (a - x_i[j]);
                L_i_denr *= (x_i[i] - x_i[j]);
            }
        }
        L_i = L_i_numr / L_i_denr;
        result += f_x_i[i] * L_i;
    }
    return result;
}
