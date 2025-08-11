#ifndef POLY_HPP
#define POLY_HPP

#include<iostream>
#include<vector>
#include<cmath>
class Polynomial
{
    private:
        std::vector<double> coefficients;
        int size;
    public:
        Polynomial(std::vector<double>& coeffs) : coefficients(coeffs),size(coeffs.size()) {} 
        double evaluate(double x);
        Polynomial derivative();
        Polynomial add(Polynomial &other);
        Polynomial mul(Polynomial &other);
        void print(); 

};

#endif