#include "Matrix.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    std::string filename = "/workspaces/NumericalComputing/Matrix/matrices/49X49.txt";
    Matrix A(filename);
    Matrix L(A.getRow(),A.getCol());
    Matrix U(A.getRow(),A.getCol());

    A.CroutsLUDecomposition(L, U);

    std::vector<long double> x = A.solveLU(L, U);

    std::cout << "Solution: ";
    for (double val : x) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}