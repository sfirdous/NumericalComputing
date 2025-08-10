#include "Polynomial.hpp"
#include<vector>
using namespace std;

int main()
{

    vector<double> poly = {1,1,1,1};
    Polynomial p(poly);
    Polynomial ans = p.add(p);
    ans.print();
    


    return 0;
}