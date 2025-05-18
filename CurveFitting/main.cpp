#include <iostream>
#include <iomanip>
#include "CurveFit.hpp"

using namespace std;

int main()
{

    CurveFit cf("D:\\NumericalComputing\\CurveFitting\\data\\example1.txt");
   
    auto ans = cf.quadraticLeastSquaresFit();
    cout << ans.evaluate(1) << endl;
    
    return 0;
}
