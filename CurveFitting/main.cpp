#include <iostream>
#include <iomanip>
#include "CurveFit.hpp"

using namespace std;

int main() {

    CurveFit cf("/workspaces/NumericalComputing/CurveFitting/data/example1.txt");


    cf.linearLeastSquaresFit();
    auto result = cf.getResult();
    cout << result.a << "\t" << result.b << endl;

    cf.quadraticLeastSquaresFit();
    auto qResult = cf.getResult();
    cout << qResult.a << "\t" << qResult.b << "\t" << endl;

    cf.exponentialFit(ae, be);
    auto eResult = cf.getResult();
    cout << eResult.a << "\t" << eResult.b << endl;

    cf.powerFit(ap, bp);
    auto pResult = cf.getResult();
    cout << pResult.a << "\t" << pResult.b << endl;

    return 0;
}
