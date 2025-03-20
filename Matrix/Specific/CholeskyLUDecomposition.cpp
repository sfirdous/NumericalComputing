#include "Matrix.hpp"
#include <cmath>

void Matrix::CholeskyLUDecomposition(Matrix &L) {
    if (!this->isSymmetric()) {
        std::cout << "Matrix not Symmetric" << std::endl;
        exit(1);
    }

    for (int i = 0; i < nRows; i++) {
        L.matrix[i][i] = sqrt(matrix[i][i]);
        for (int k = i + 1; k < nRows; k++) {
            long double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L.matrix[k][j] * L.matrix[i][j];
            }
            L.matrix[k][i] = (matrix[k][i] - sum) / L.matrix[i][i];
        }
    }
}