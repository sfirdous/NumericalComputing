#include "Matrix.hpp"

void Matrix::DolittlesLUDecomposition(Matrix &L, Matrix &U) {
    if (nRows != nCols-1) {
        std::cout << "Matrix must be square for LU decomposition." << std::endl;
        return;
    }

    // L = Matrix(nRows, nCols);
    // U = Matrix(nRows, nCols);

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            L.matrix[i][j] = (i == j) ? 1.0 : 0.0; // L diagonals are 1
            U.matrix[i][j] = 0.0;
        }
    }

    for (int i = 0; i < nRows; i++) {
        for (int k = i; k < nCols; k++) {
            long double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L.matrix[i][j] * U.matrix[j][k];
            }
            U.matrix[i][k] = matrix[i][k] - sum;
        }

        if (fabs(U.matrix[i][i]) < 1e-12) {
            std::cout << "LU decomposition failed: Zero pivot encountered at row " << i << "." << std::endl;
            return;
        }

        for (int k = i + 1; k < nRows; k++) {
            long double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L.matrix[k][j] * U.matrix[j][i];
            }
            L.matrix[k][i] = (matrix[k][i] - sum) / U.matrix[i][i];
        }
    }
}
