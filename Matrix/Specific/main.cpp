#include "Matrix.hpp"
#include <iostream>
#include <vector>

int main() {
    // int rows, cols;
    // std::cout << "Enter number of equations (rows): ";
    // std::cin >> rows;
    // cols = rows + 1; // Augmented matrix has an extra column

    // Matrix A(rows, cols);
    // std::cout << "Enter the augmented matrix row by row:" << std::endl;
    // A.setValues();


    //     std::vector<double> solution = A.gaussianElimination();
    //     std::cout << "Solution:\n";
    //     for (size_t i = 0; i < solution.size(); ++i) {
    //         std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
    //     }
    

    // std::string filename = "D:\\NumericalComputing\\Matrix\\matrices\\49X50.txt";

    // // Create a matrix from the file
    // Matrix A(filename);

    // // Display the matrix
    // std::cout << "Matrix:\n" << A << std::endl;

    // // Solve using Gaussian Elimination
    // std::vector<double> solution = A.gaussianElimination();

    // // Display the solution
    // std::cout << "Solution:\n";
    // for (size_t i = 0; i < solution.size(); ++i) {
    //     std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
    // }

//     Matrix A(2, 2);
    
//     // Manually set values for A
    
//             A.setValues(); 

//     // Create L and U matrices
//     Matrix L(2, 3), U(2, 2);

//     // Perform LU Decomposition
//     A.LUDecomposition(L, U);

//     // Print L matrix
//     // std::cout << "Lower Triangular Matrix L:\n";
//     // std::cout << L << std::endl;
    

//     // // Print U matrix
//     // std::cout << "Upper Triangular Matrix U:\n" << U << std::endl ;


std::string filename = "/workspaces/NumericalComputing/Matrix/matrices/49X49.txt";

    
    Matrix A(filename);
    Matrix L(A.getRow(),A.getCol()), U(A.getRow(),A.getCol());

    A.LUDecomposition(L, U);

    std::cout << "Lower Triangular Matrix L:\n";
    std::cout << L << std::endl;

     
 std::cout << "Upper Triangular Matrix U:\n" << U << std::endl ;

    return 0;
}
