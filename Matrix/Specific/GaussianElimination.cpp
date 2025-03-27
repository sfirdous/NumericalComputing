#include "Matrix.hpp"
#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<long double>> Matrix::rowReduction() {
    for (int i = 0; i < nRows; i++) {
        // Pivoting to avoid division by zero
        if (fabs(matrix[i][i]) < 1e-12) {
            std::cerr << "Zero pivot encountered at row " << i << "!" << std::endl;
            exit(1);
        }
        
        // Normalize pivot row
        long double pivot = matrix[i][i];
        for (int j = 0; j < nCols; j++) {
            matrix[i][j] /= pivot;
        }
        
        // Eliminate below pivot
        for (int k = i + 1; k < nRows; k++) {
            long double factor = matrix[k][i];
            for (int j = 0; j < nCols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    return matrix;
}

std::vector<long double> Matrix::backSubstitution(std::vector<std::vector<long double>> &reducedMat) {
    std::vector<long double> solution(nRows, 0);
    for (int i = nRows - 1; i >= 0; i--) {
        long double sum = reducedMat[i][nCols - 1];
        for (int j = i + 1; j < nRows; j++) {
            sum -= reducedMat[i][j] * solution[j];
        }
        solution[i] = sum / reducedMat[i][i];
    }
    return solution;
}

std::vector<long double> Matrix::gaussianElimination() {
    std::vector<std::vector<long double>> reducedMat = this->rowReduction();
    return this->backSubstitution(reducedMat);
}
