#include "Polynomial.hpp"
#include<vector>
using namespace std;

int main()
{

    vector<double> poly = {2,-1,1};
    Polynomial p(poly);
    vector<double> poly1 = {2,1};
    Polynomial p1(poly1);
    Polynomial ans = p.mul(p1);
    ans.print();
    


    return 0;
}