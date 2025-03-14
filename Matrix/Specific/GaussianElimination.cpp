#include "Matrix.hpp"
#include <vector>
#include <iostream>
#include <algorithm> // For std::swap_ranges

bool Matrix::basicPivoting() {
    for (int i = 0; i < nRows; i++) {
        if (matrix[i][i] == 0) {
            bool swapped = false;
            for (int k = i + 1; k < nRows; k++) {
                if (matrix[k][i] != 0) {
                    std::swap_ranges(matrix[i], matrix[i] + nCols, matrix[k]); // Swap row contents
                    swapped = true;
                    break;
                }
            }
            if (!swapped) {
                return false; // No valid pivot found, singular matrix
            }
        }
    }
    return true;
}

void Matrix::forwardElimination() {
    for (int i = 0; i < nRows - 1; i++) { // Avoid out-of-bounds
        if (matrix[i][i] == 0) { // Check zero pivot before division
            std::cout << "Zero pivot encountered at row " << i << std::endl;
            return;
        }
        for (int k = i + 1; k < nRows; k++) {
            long double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < nCols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}

std::vector<long double> Matrix::backSubstitution() {
    std::vector<long double> solution(nRows, 0);
    for (int i = nRows - 1; i >= 0; i--) {
        if (matrix[i][i] == 0) { // Prevent division by zero
            std::cout << "Back substitution failed: zero pivot at row " << i << std::endl;
            exit(1);
        }
        solution[i] = matrix[i][nCols - 1];
        for (int j = i + 1; j < nRows; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i]; // Divide by diagonal element
    }
    return solution;
}

std::vector<long double> Matrix::gaussianElimination() {
    Matrix tempMatrix(*this); // Copy the original matrix
    if (!tempMatrix.basicPivoting()) {
        std::cout << "Pivoting Failed: Singular matrix detected." << std::endl;
        return {};
    }
    tempMatrix.forwardElimination();
    return tempMatrix.backSubstitution();
}
