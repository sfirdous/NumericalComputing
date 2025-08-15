#include <iostream>
#include <vector>
#include <fstream>
#include "../Polynomial/Polynomial.hpp"
#include <cmath>

#ifndef INTERPOLATE_HPP
#define INTERPOLATE_HPP

class Interpolation{

  private:
  int n;
  std::vector<double> x;
  std::vector<double> fx;
  std::vector<Polynomial> P;

  public:
  //Constructors
  Interpolation() { n = 0;}
  Interpolation(int size);
  Interpolation(std::string filename);
  Interpolation(std::vector<double> x_prime,std::vector<double> fx_prime) : x(x_prime) , fx(fx_prime) , n(x.size()){}
  Interpolation(const Interpolation &other);

  //Getters
  int getSize(){return n;}
  std::vector<double> getX(){return x;}
  std::vector<double> getfX(){return fx;}

  //Setters
  void setSize(int n){this->n = n;}

  //Interpolation
  double lagrangesInterpolation(double x);
  double linearSplineInterpolation(double a);

  //Least Sqaure
  Polynomial linearLeastSquaresFit();
  Polynomial quadraticLeastSquaresFit();
  Polynomial exponentialFit();
  Polynomial powerFit();

  //
  void calculateFallingFactorial();
};



#endif