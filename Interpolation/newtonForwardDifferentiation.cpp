#include "Interpolation.hpp"
#include "./Polynomial/Polynomial.hpp"

void Interpolation::calculateFallingFactorial()
{
    P.resize(n) ; // store P through P[n]

    std::vector<double> temp = {1};
    // Base case: (x)_0 = 1
    P[0]= Polynomial(temp);

        std::vector<double> temp2 = {{0, 1}};

    // (x)_1 = x
    P[1] = Polynomial(temp2);

    // General case
    for(int i = 2; i < n; ++i)
    { 
        // Polynomial for (x - (i-1))
        std::vector<double> p1 = { -double(i-1), 1 };

        Polynomial poly = Polynomial(p1);
        P[i] = P[i-1].mul(poly);
    }
}
