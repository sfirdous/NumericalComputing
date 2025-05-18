#include "Polynomial.hpp"
#include<vector>
using namespace std;

int main()
{

    vector<double> poly = {-1,-1,0,1};
    Polynomial p(poly);
    double ans = p.evaluate(0);
    Polynomial deriv = p.derivative();
    double dans = deriv.evaluate(1);
    cout << ans << endl;


    return 0;
}