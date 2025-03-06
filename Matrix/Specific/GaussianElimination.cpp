#include "Matrix.hpp"
#include <vector>


void Matrix::basicPivoting() {
    for (int i = 0; i < nRows; i++) {
        if (matrix[i][i] == 0) {
            for (int k = i + 1; k < nRows; k++) {
                if (matrix[k][i] != 0) {
                    std::swap(matrix[i], matrix[k]); // Swap rows
                    break;
                }
            }
        }
    }
}

void Matrix::forwardElimination() {
    for (int i = 0; i < nRows; i++) {
        for (int k = i + 1; k < nRows; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < nCols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}

std::vector<double> Matrix::backSubstitution() {
    std::vector<double> solution(nRows, 0);
    for (int i = nRows - 1; i >= 0; i--) {
        solution[i] = matrix[i][nCols - 1];
        for (int j = i + 1; j < nRows; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }
    return solution;
}

std::vector<double> Matrix::gaussianElimination() {
    Matrix tempMatrix(*this); // Copy the original matrix
    tempMatrix.basicPivoting();
    tempMatrix.forwardElimination();
    return tempMatrix.backSubstitution();
}
