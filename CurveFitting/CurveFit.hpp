#include <iostream>

class CurveFit
{
  private:
  int n;
  long double *x_i;
  long double *f_x_i;
 
  public:
  CurveFit();
  CurveFit(int n);
  CurveFit(std::string filename);

  void setN(int n){this->n = n;}
  int getN(){return n;}

  void allocateMemory();
  long double lagrangesInterpolation(long double a);

  ~CurveFit();


};