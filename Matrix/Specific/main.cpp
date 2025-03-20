#include "Matrix.hpp"
#include <iostream>
#include <vector>

int main() {
  
    std::string filename = "D:\\NumericalComputing\\Matrix\\matrices\\255X255.txt";  

    // Load the matrix from the file
    Matrix A(filename);

    if (A.getRow() == 0 || A.getCol() == 0) {
        std::cerr << "Error: Matrix loading failed.\n";
        return 1; // Exit if the matrix is invalid
    }

    // Solve using Gauss-Seidel
    std::vector<long double> solution = A.gaussSeidel(500, 1e-6); // 500 iterations, tolerance 1e-6

    // Display the solution
    if (!solution.empty()) {
        std::cout << "Solution:\n";
        for (size_t i = 0; i < solution.size(); ++i) {
            std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
        }
    } else {
        std::cout << "Gauss-Seidel method failed to find a solution.\n";
    }

    return 0;
}
