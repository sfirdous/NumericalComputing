#include "Matrix.hpp"
#include <iostream>
#include <vector>

int main() {
    // Example system:
    // 2x + 3y - 1z = 5
    // 4x + 4y - 3z = 3
    // -2x + 3y - 1z = 1

    int rows = 3;
    int cols = 4; // Augmented matrix includes constants (Ax = b → A|b)

    Matrix mat(rows, cols);
    mat.allocateMemory();

    // Setting values manually
    mat.setValue(0, 0, 2);   mat.setValue(0, 1, 3);   mat.setValue(0, 2, -1);  mat.setValue(0, 3, 5);
    mat.setValue(1, 0, 4);   mat.setValue(1, 1, 4);   mat.setValue(1, 2, -3);  mat.setValue(1, 3, 3);
    mat.setValue(2, 0, -2);  mat.setValue(2, 1, 3);   mat.setValue(2, 2, -1);  mat.setValue(2, 3, 1);

    std::cout << "Original Augmented Matrix (A|b):" << std::endl;
    std::cout << mat << std::endl;

    std::vector<long double> solution = mat.gaussianElimination();

    std::cout << "Solution (x):" << std::endl;
    for (size_t i = 0; i < solution.size(); ++i) {
        std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
    }

    return 0;
}
