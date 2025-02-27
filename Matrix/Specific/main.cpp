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
    

    std::string filename = "D:\\NumericalComputing\\Matrix\\matrices\\augMatrix.txt";

    // Create a matrix from the file
    Matrix A(filename);

    // Display the matrix
    std::cout << "Augmented Matrix:\n" << A << std::endl;

    // Solve using Gaussian Elimination
    std::vector<double> solution = A.gaussianElimination();

    // Display the solution
    std::cout << "Solution:\n";
    for (size_t i = 0; i < solution.size(); ++i) {
        std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
    }

    return 0;
}
