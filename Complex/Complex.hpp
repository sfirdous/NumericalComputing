#include <iostream>

class Complex
{

private:
    double real, imag;

public:
    // Constructor Declaration
    Complex();
    Complex(double r, double i);
    Complex(const Complex &c);

    // Method Declaration
    double getReal() const;
    double getImag() const;
    void set(double r, double i);

    // Operator OverLoading
    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator*(const Complex &c);

    friend std::ostream &operator<<(std::ostream &os, Complex &c);
};