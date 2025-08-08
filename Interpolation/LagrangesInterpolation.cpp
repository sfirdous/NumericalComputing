#include "Interpolation.hpp"

double Interpolation::lagrangesInterpolation(double a)
{
    double result = 0.0;
    for(int i = 0;i < n;++i)
    {
        double term = fx[i];
        for(int j = 0; j < n;++j)
            if(i!=j)
                term *= (a - x[j]) / (x[i] - x[j]);
        result += term;
    }

    return result;
}
