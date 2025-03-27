#include "Matrix.hpp"
#include <vector>
#include <iostream>

std::vector<long double> Matrix::forwardSolve() {
    int n = this->getRow();
    std::vector<long double> y(n, 0.0);
    
    // Extract b (last column of A)
    std::vector<long double> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = this->matrix[i][this->getCol() - 1];
    }
    
    for (int i = 0; i < n; i++) {
        long double sum = 0.0;
        for (int j = 0; j < i; j++) {
            sum += this->matrix[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / this->matrix[i][i];
    }
    return y;
}

std::vector<long double> Matrix::backwardSolve(const std::vector<long double> &y) {
    int n = this->getRow();
    std::vector<long double> x(n, 0.0);
    
    for (int i = n - 1; i >= 0; i--) {
        long double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += this->matrix[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / this->matrix[i][i];
    }
    return x;
}


std::vector<long double> Matrix::solveLU(Matrix &L, Matrix &U) {
    std::vector<long double> y = L.forwardSolve();
    std::vector<long double> x = U.backwardSolve(y);
    return x;
}