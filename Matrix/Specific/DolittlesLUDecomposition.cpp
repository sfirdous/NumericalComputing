#include "Matrix.hpp"
void Matrix::DolittlesLUDecomposition(Matrix &L, Matrix &U) {
    if (nRows != nCols) {
        std::cout << "Matrix must be square for LU decomposition." << std::endl;
        return;
    }

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            if (i == j) {
                L.matrix[i][j] = 1.0; // L diagonal elements are 1
            } else {
                L.matrix[i][j] = 0.0;
            }
            U.matrix[i][j] = 0.0;
        }
    }

    
    for (int i = 0; i < nRows; i++) {
        // Compute upper triangular matrix U
        for (int k = i; k < nCols; k++) {
            long double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L.matrix[i][j] * U.matrix[j][k];
            }
            U.matrix[i][k] = matrix[i][k] - sum;
        }

        // Check for zero pivot to avoid division by zero
        if (U.matrix[i][i] == 0) {
            std::cout << "LU decomposition failed: Zero pivot encountered at row " << i << "." << std::endl;
            return;
        }

        // Compute lower triangular matrix L
        for (int k = i + 1; k < nRows; k++) {
            long double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L.matrix[k][j] * U.matrix[j][i];
            }
            L.matrix[k][i] = (matrix[k][i] - sum) / U.matrix[i][i];
        }
    }
}


