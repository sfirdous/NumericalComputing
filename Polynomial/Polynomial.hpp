#ifndef POLY_HPP
#define POLY_HPP

#include<iostream>
#include<vector>
#include<cmath>
class Polynomial
{
    private:
        std::vector<double> coefficients;
    public:
        Polynomial(std::vector<double>& coeffs) : coefficients(coeffs) {} 
        double evaluate(double x);
        Polynomial derivative();

};

#endif