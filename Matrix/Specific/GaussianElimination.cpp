#include "Matrix.hpp"
#include <vector>

std::vector<double> Matrix::gaussianElimination() {
    // Create a copy of the original matrix using the Matrix class
    Matrix tempMatrix(*this);

    // Basic Pivoting
    for (int i = 0; i < tempMatrix.nRows; i++) {
        if (tempMatrix.matrix[i][i] == 0) {
            for (int k = i + 1; k < tempMatrix.nRows; k++) {
                if (tempMatrix.matrix[k][i] != 0) {
                    std::swap(tempMatrix.matrix[i], tempMatrix.matrix[k]);
                    break;
                }
            }
        }

        // Forward Elimination
        for (int k = i + 1; k < tempMatrix.nRows; k++) {
            double factor = tempMatrix.matrix[k][i] / tempMatrix.matrix[i][i];
            for (int j = i; j < tempMatrix.nCols; j++) {
                tempMatrix.matrix[k][j] -= factor * tempMatrix.matrix[i][j];
            }
        }
    }

    // Back Substitution
    std::vector<double> solution(tempMatrix.nRows, 0);
    for (int i = tempMatrix.nRows - 1; i >= 0; i--) {
        solution[i] = tempMatrix.matrix[i][tempMatrix.nCols - 1];
        for (int j = i + 1; j < tempMatrix.nRows; j++) {
            solution[i] -= tempMatrix.matrix[i][j] * solution[j];
        }
        solution[i] /= tempMatrix.matrix[i][i];
    }

    return solution;
}
