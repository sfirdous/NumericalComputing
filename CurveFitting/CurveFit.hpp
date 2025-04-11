#ifndef CURVEFIT_HPP
#define CURVEFIT_HPP
#include <iostream>

class CurveFit
{
  private:
  int n;
  long double *x_i;
  long double *f_x_i;
  
  struct Result{
    long double a;
    long double b;
    long double c;
  };

  Result resultstruct;
 
  public:
  CurveFit();
  CurveFit(int n);
  CurveFit(std::string filename);

  void setN(int n){this->n = n;}
  int getN(){return n;}
  Result getResult(){
    return resultstruct;
  }

  void allocateMemory();
  long double lagrangesInterpolation(long double a);

  void linearLeastSquaresFit();
  void powerFit();
  void exponentialFit();
  void quadraticLeastSquaresFit();

  ~CurveFit();


};


#endif
