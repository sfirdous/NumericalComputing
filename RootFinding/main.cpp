#include"RootFinding.hpp"
using namespace  std;

int main(){

    double a,b;
    RootFinding R;
    double bRoot = R.bisection(a,b);
    double nRoot = R.newtonRaphson();
    double fRoot = R.fixedPointIteration();

    return 0;
}
