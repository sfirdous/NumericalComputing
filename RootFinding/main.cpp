#include"RootFinding.hpp"
using namespace  std;

int main(){

   RootFinding R;
   vector<double> p = {-1,-1,0,1};
   Polynomial poly(p);
   double broot = R.bisection(poly);
   double nroot = R.newtonRaphson(poly);
   cout << nroot << endl;
   vector<double> g = {1,1};
   Polynomial gx(g);
   double froot = R.fixedPoint(poly,gx,1.0/3.0);
   cout << froot << endl;

    return 0;
}
