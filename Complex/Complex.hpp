#include <iostream>

class Complex
{
private:
    double real, imag;

public:
    // Constructor Declaration
    Complex();
    Complex(double r, double i);
    Complex(Complex &c);

    // Method Declaration
    double getReal();
    double getImag();
    void set(double r, double i);

    //Operator OverLoading
    Complex operator+(Complex& c);
    Complex operator-(Complex& c);
    Complex operator*(Complex& c);

    friend std::ostream& operator<<(std::ostream& os, Complex& c);

};