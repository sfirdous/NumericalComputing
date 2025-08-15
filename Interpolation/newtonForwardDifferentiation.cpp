#include "Interpolation.hpp"

void Interpolation::calculateFallingFactorial()
{
    P.resize(n);

   std::vector<double> p = {0,1};
    P[1] = Polynomial(p);

    
    for(int i = 2 ; i < n ; ++i)
       { 
        std::vector<double> p1 = {double(i-1),1};
        Polynomial poly = Polynomial(p1);

        P[i] = P[i-1].mul(poly);}

}

