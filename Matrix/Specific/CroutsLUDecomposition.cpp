#include "Matrix.hpp"

void Matrix::CroutsLUDecomposition(Matrix &L, Matrix &U) {
    if (nRows != nCols) {
        std::cout << "Matrix must be square for LU decomposition." <<std::endl;
        return;
    }

    L = Matrix(nRows, nCols);
    U = Matrix(nRows, nCols);

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            U.matrix[i][j] = (i == j) ? 1.0 : 0.0; // U diagonals are 1
            L.matrix[i][j] = 0.0;
        }
    }

    for (int i = 0; i < nRows; i++) {
        for (int j = i; j < nCols; j++) {
            long double sum = 0;
            for (int k = 0; k < i; k++) {
                sum += L.matrix[j][k] * U.matrix[k][i];
            }
            L.matrix[j][i] = matrix[j][i] - sum;
        }

        for (int j = i + 1; j < nCols; j++) {
            long double sum = 0;
            for (int k = 0; k < i; k++) {
                sum += L.matrix[i][k] * U.matrix[k][j];
            }
            U.matrix[i][j] = (matrix[i][j] - sum) / L.matrix[i][i];
        }
    }
}
