#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>

class Complex
{
private:
    double real;
    double imag;

public:
    // Constructors
    Complex();
    Complex(double r, double i);
    Complex(const Complex &other);

    // Getters
    double getReal() { return real; }
    double getImag() { return imag; }

    // Setters
    void set(double r, double i)
    {
        real = r;
        imag = i;
    }
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    // Operator Overloads
    Complex operator+(Complex &b);
    Complex operator-(Complex &b);
    Complex operator*(Complex &b);
    Complex operator=(const Complex &other);

    //operation functions
    Complex add(Complex& b);
    Complex sub(Complex& b);
    Complex mul(Complex& b);

    // friend functions
    friend std::ostream& operator<<(std::ostream &out, Complex &c);
    friend std::istream& operator>>(std::istream &in, Complex &c);
};

#endif