#include "Matrix.hpp"

// Check if matrix is Identity
bool Matrix::isIdentity() const {
    if (nRows != nCols)
        return false;

    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            if (i == j && matrix[i][j] != 1)
                return false;
            else if (i != j && matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

// Check if matrix is Symmetric
bool Matrix::isSymmetric() const {
    if (nRows != nCols)
        return false;

    for (int i = 0; i < nRows; ++i) {
        for (int j = i + 1; j < nCols; ++j) {
            if (matrix[i][j] != matrix[j][i])
                return false;
        }
    }
    return true;
}


