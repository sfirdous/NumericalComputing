#include "Matrix.hpp"

// Addition
Matrix Matrix::add(const Matrix &B) const {
    Matrix result(nRows, nCols);
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            result.matrix[i][j] = this->matrix[i][j] + B.getValue(i, j);
        }
    }
    return result;
}

// Subtraction
Matrix Matrix::sub(const Matrix &B) const {
    Matrix result(nRows, nCols);
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            result.matrix[i][j] = this->matrix[i][j] - B.getValue(i, j);
        }
    }
    return result;
}

// Multiplication
Matrix Matrix::mul(const Matrix &B) const {
    Matrix result(this->nRows, B.getCol());
    for (int i = 0; i < this->nRows; ++i) {
        for (int j = 0; j < B.getCol(); ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < this->nCols; k++) {
                result.matrix[i][j] += this->matrix[i][k] * B.getValue(k, j);
            }
        }
    }
    return result;
}
