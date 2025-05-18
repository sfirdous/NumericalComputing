#include "Matrix.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    Matrix M("D:\\NumericalComputing\\Matrix\\matrices\\augMatrix.txt");
    auto ans = M.gaussSeidel(1e-3);

    
    return 0;
}
