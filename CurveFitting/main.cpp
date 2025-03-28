#include "CurveFit.hpp"

int main() {
    CurveFit curveFit("/workspaces/NumericalComputing/CurveFitting/data/example1.txt");    

    long double a = 2.5;
    long double result = curveFit.lagrangesInterpolation(a);
    std::cout << "f(" << a << ") = " << result << std::endl;

    return 0;
}