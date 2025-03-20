#include "Matrix.hpp"

// Check if matrix is Identity
bool Matrix::isIdentity() {
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
bool Matrix::isSymmetric() {
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


bool Matrix::isDiagonallyDominant()  {
    for (int i = 0; i < nRows; i++) {
        long double sum = 0;
        for (int j = 0; j < nCols - 1; j++) // Exclude last column
        {  
            if (i != j) {
                sum += std::fabs(matrix[i][j]);
            }
        }
        if (std::fabs(matrix[i][i]) < sum) {
            return false; // Not diagonally dominant
        }
    }
    return true;
}

