#include "Complex.hpp"
using namespace std;

// Constructors
Complex::Complex()
{
    real = imag = 0.0;
}

Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}


//const added so no error occurs for rvalue (i.e temp val)
Complex::Complex(const Complex &other)
{
    real = other.real;
    imag = other.imag;
}


Complex Complex::add(Complex& b){return *this+b;}
Complex Complex::sub(Complex& b){return *this-b;}
Complex Complex::mul(Complex& b){return *this*b;}

// Operator Overloads
Complex Complex::operator+(Complex &b)
{
    Complex ans;
    ans.set(real + b.real, imag + b.imag);
    return ans;
}
Complex Complex::operator-(Complex &b)
{
    Complex ans;
    ans.set(real - b.getReal(), imag - b.getImag());
    return ans;
}
Complex Complex::operator*(Complex &b)
{
    Complex ans;
    double x = real * b.getReal() + imag * b.getImag();
    double y = imag * b.getReal() + real * b.getImag();
    b.set(x, y);
    return ans;
}

Complex Complex::operator=(const Complex &other) 
{
    real = other.real;
    imag = other.imag;
}

// friend functions
ostream& operator<<(ostream& out, Complex &c)
{
    if (c.getImag() < 0)
        out << c.getReal() << " " << c.getImag() << "i" << endl;

    out << c.getReal() << "+" << c.getImag()<< "i" << endl;
    return out;
}

istream& operator>>(istream& in, Complex &c)
{
    cout << "Enter real part" << endl;
    in >> c.real;
    cout << "Enter Imag part" << endl;
    in >> c.imag;
    return in;
}
