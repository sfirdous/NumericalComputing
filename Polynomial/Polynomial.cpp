#include "Polynomial.hpp"

double Polynomial::evaluate(double x)
{
    double result = 0.0;
    for(int i = 0 ; i < coefficients.size() ; ++i)
        result += coefficients[i] * std::pow(x,i);
    return result;
}

Polynomial Polynomial::derivative()
{
    std::vector<double> derivCoeffs;
    for(int i = 0 ; i < coefficients.size() ; ++i)
           derivCoeffs.push_back(i * coefficients[i]);
    return Polynomial(derivCoeffs);
}