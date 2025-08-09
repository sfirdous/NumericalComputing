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

Polynomial Polynomial::add(Polynomial &other)
{
    std::vector<double> result;
    if(other.size > size)
            coefficients.resize(size + other.size - 1,0);
    else
            other.coefficients.resize(size + size - 1,0);

    for(int i = 0 ; i < size ; ++i)
        result[i] = coefficients[i] + other.coefficients[i];
    
    return result;
}

void Polynomial::print()
{
    std::cout << coefficients[0] << " " ; // print the first coefficient
    for(int i = 1 ; i < size ; ++i)
        std::cout << coefficients[i] << "x^" << i << " ";
}
