#include "Matrix.hpp"
#include <iostream>
#include <vector>
#include <cmath>

// Forward Elimination with pivoting
long double** Matrix::rowReduction() {
    for (int i = 0; i < nRows; i++) {
        // Pivoting: Find the max pivot in the current column below (and including) i
        int maxRow = i;
        for (int k = i + 1; k < nRows; k++) {
            if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }
        // Swap if needed
        if (fabs(matrix[maxRow][i]) < 1e-12) {
            std::cerr << "Zero pivot encountered at column " << i << "!" << std::endl;
            exit(1);
        }
        if (maxRow != i) {
            std::swap(matrix[i], matrix[maxRow]);
        }

        // Normalize pivot row
        long double pivot = matrix[i][i];
        for (int j = 0; j < nCols; j++) {
            matrix[i][j] /= pivot;
        }

        // Eliminate rows below
        for (int k = i + 1; k < nRows; k++) {
            long double factor = matrix[k][i];
            for (int j = 0; j < nCols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    return matrix;
}

std::vector<long double> Matrix::backSubstitution(long double** reducedMat) {
    std::vector<long double> solution(nRows, 0);
    for (int i = nRows - 1; i >= 0; i--) {
        long double sum = reducedMat[i][nCols - 1];
        for (int j = i + 1; j < nCols - 1; j++) {
            sum -= reducedMat[i][j] * solution[j];
        }
        solution[i] = sum / reducedMat[i][i];
    }
    return solution;
}


// Gaussian elimination wrapper
std::vector<long double> Matrix::gaussianElimination() {
    long double** reducedMat = this->rowReduction();
    return this->backSubstitution(reducedMat);
}
