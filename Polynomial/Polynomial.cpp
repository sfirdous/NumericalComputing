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
    int max_size = std::max(size,other.size);
    std::vector<double> result(max_size,0.0);

    for(int i = 0 ; i < size ; ++i)
        result[i] += coefficients[i];
    for(int i = 0 ; i < other.size ; ++i)
        result[i] += other.coefficients[i];
    
    return Polynomial(result);
}

Polynomial Polynomial::mul(Polynomial &other)
{
    std::vector<double> result(size+other.size,0.0);
    int s_size,l_size;

    const std::vector<double> *outer,*inner;
    //decide the outer and inner loop based on the size of the polynomials
    if(size >= other.size)
    {
        outer = &other.coefficients;
        inner = &coefficients;        
    }else{
        outer = &coefficients;
        inner = &other.coefficients;
    
    }

    for(int i = 0 ; i < outer->size() ; ++i)
        for(int j = 0 ; j < inner->size() ; ++j)
                result[i+j] += (*outer)[i] + (*inner)[j];

    return Polynomial(result);
}


void Polynomial::print()
{
    std::cout << coefficients[0] << " " ; // print the first coefficient
    for(int i = 1 ; i < size ; ++i)
        std::cout << coefficients[i] << "x^" << i << " ";
}
