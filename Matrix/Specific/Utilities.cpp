#include "Matrix.hpp"

// Allocate memory for matrix
void Matrix::allocateMemory() {
    matrix = new long double *[nRows];
    for (int i = 0; i < nRows; ++i) {
        matrix[i] = new long double[nCols];
    }
}

// Set values from user input
void Matrix::setValues() {
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}