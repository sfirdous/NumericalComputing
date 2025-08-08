#include <iostream>
#include <iomanip>
#include "Interpolation.hpp"

using namespace std;

int main()
{

    Interpolation cf("D:\\NumericalComputing\\Interpolation\\data\\example1.txt");
   
    auto ans = cf.quadraticLeastSquaresFit();
    cout << ans.evaluate(1) << endl;
    
    return 0;
}
