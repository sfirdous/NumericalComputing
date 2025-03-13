#include "Matrix.hpp"
#include <iostream>
#include <vector>

int main() {



std::string filename = "/workspaces/NumericalComputing/Matrix/matrices/255X255.txt";

    
    Matrix A(filename);
    Matrix L(A.getRow(),A.getCol()), U(A.getRow(),A.getCol());

    std::vector<long double> solution = A.gaussianElimination();
    for (int i = 0; i < solution.size(); ++i) {
        std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
    }


    // A.DolittlesLUDecomposition(L, U);

    

    // // A.CroutsLUDecomposition(L,U);
    // A.CholeskyDecomposition(L);
    // std::cout << "Lower Triangular Matrix L:\n";
    // std::cout << L << std::endl;

     
    // // std::cout << "Upper Triangular Matrix U:\n" << U << std::endl ;

    return 0;
}
