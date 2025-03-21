#include "Matrix.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  
    std::string filename = "/workspaces/NumericalComputing/Matrix/matrices/255X255.txt";  

    Matrix C(filename);
    

    // std::vector<long double> solution = C.gaussianElimination(); 
    // std::cout << "Solution:\n";
    // for (size_t i = 0; i < solution.size(); ++i) 
    //         std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
    
    

    // Matrix A(3,4);
    // A.setValues();


    // std::vector<long double> solutionS = A.gaussSeidel(500, 0.00001);
    // std::vector<long double> solutionJ = A.gaussJacobi(500, 0.00001);

    // if (!solutionS.empty()) 
    // {
    //     std::cout << "Solution:\n";
    //     for (size_t i = 0; i < solutionS.size(); ++i) 
    //         std::cout << "x" << i + 1 << " = " << solutionS[i] << std::endl;
    // } 
    // else {
    //         std::cout << "Gauss-Seidel method failed to find a solution.\n";
    // }

    // if (!solutionJ.empty()) 
    // {
    //     std::cout << "Solution:\n";
    //     for (size_t i = 0; i < solutionJ.size(); ++i) 
    //         std::cout << "x" << i + 1 << " = " << solutionJ[i] << std::endl;
    // } 
    // else {
    //         std::cout << "Gauss-Seidel method failed to find a solution.\n";
    // }

    std::vector<long double> solutionS = C.gaussJacobi(500, 0.00001);
    

    return 0;
}
