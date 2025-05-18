#include <iostream>
#include <vector>
#include <fstream>
#include "../Polynomial/Polynomial.hpp"
#include <cmath>

#ifndef CURVE_FIT_HPP
#define CURVE_FIT_HPP

class CurveFit{

  private:
  int n;
  std::vector<double> x;
  std::vector<double> fx;

  public:
  //Constructors
  CurveFit() { n = 0;}
  CurveFit(int size);
  CurveFit(std::string filename);
  CurveFit(std::vector<double> x_prime,std::vector<double> fx_prime) : x(x_prime) , fx(fx_prime) , n(x.size()){}
  CurveFit(const CurveFit &other);

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
};



#endif