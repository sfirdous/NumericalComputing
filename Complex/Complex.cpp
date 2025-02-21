#include "Complex.hpp"

//Constructor Definations
Complex::Complex()
{
    real = imag = 0.0;
}

Complex::Complex(double r, double i)
{
    this->real = r;
    this->imag = i;
}

Complex::Complex(const Complex &c)
{
    this->real = c.getReal();
    this->imag = c.getImag();
}


//Method Defination
double Complex::getReal() const 
{
    return real;
}

double Complex::getImag() const 
{
    return imag;
}

void Complex::set(double r, double i)
{
    this->real = r;
    this->imag = i;
}

//Operator OverLoading Definations

Complex Complex::operator+(const Complex& c){
    Complex t;
    t.set(real + c.getReal(),imag + c.getImag());
    return t;

}

Complex Complex::operator-(const Complex& c){
    Complex t;
    t.set(real + c.getReal(),imag + c.getImag());
    return t;

}

Complex Complex::operator*(const Complex& c){
    Complex t;
    double x = (real * c.getReal()) - (imag * c.getImag());
    double y = (real * c.getImag()) + (imag * c.getReal());
    t.set(x,y);
    return t;
}

std::ostream& operator<<(std::ostream& os , Complex& c){
    std::cout << c.getReal() << " + " << c.getImag() << "i" << std::endl;
}