#include "Matrix.hpp"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool Matrix::basicPivoting(int col) {
    int maxRow = col;
    for (int i = col + 1; i < nRows; i++) {
        if (fabs(matrix[i][col]) > fabs(matrix[maxRow][col])) {
            maxRow = i;
        }
    }
    if (fabs(matrix[maxRow][col]) < 0.000001) { 
        return false; 
    }
    if (maxRow != col) {
        swap(matrix[col], matrix[maxRow]); // Swap entire rows
    }
    return true;
}

// Convert Matrix into Upper Triangular Form
void Matrix::forwardElimination() {
    for (int i = 0; i < nRows - 1; i++) {
        if (!basicPivoting(i)) { 
            cout << "Pivoting Failed" << endl;
            return;
        }
        for (int k = i + 1; k < nRows; k++) {
            long double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < nCols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}


vector<long double> Matrix::backSubstitution() {
    vector<long double> solution(nRows, 0);
    for (int i = nRows - 1; i >= 0; i--) {
        if (fabs(matrix[i][i]) < 0.000001) {
            cout << "Back substitution failed: zero pivot at row " << i << endl;
            return {};
        }
        solution[i] = matrix[i][nCols - 1];
        for (int j = i + 1; j < nRows; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }
    return solution;
}

// Perform Gaussian Elimination to Solve Ax = b
vector<long double> Matrix::gaussianElimination() {
    forwardElimination();
    return backSubstitution();
}
