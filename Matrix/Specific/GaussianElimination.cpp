#include "Matrix.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Perform Partial Pivoting (Swaps Rows if Needed)
bool Matrix::basicPivoting() {
    for (int i = 0; i < nRows; i++) {
        if (matrix[i][i] == 0) { // Check if pivot is zero
            bool swapped = false;
            for (int k = i + 1; k < nRows; k++) {
                if (matrix[k][i] != 0) { 
                    swap(matrix[i], matrix[k]); // Swap entire rows
                    swapped = true;
                    break;
                }
            }
            if (!swapped) {
                return false; // No valid pivot found (Singular Matrix)
            }
        }
    }
    return true;
}

// Perform Forward Elimination to Convert into Upper Triangular Form
void Matrix::forwardElimination() {
    for (int i = 0; i < nRows - 1; i++) {
        if (matrix[i][i] == 0) { // Avoid division by zero
            cout << "Zero pivot encountered at row " << i << endl;
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

// Perform Back Substitution to Get Solution Vector
vector<long double> Matrix::backSubstitution() {
    vector<long double> solution(nRows, 0);
    for (int i = nRows - 1; i >= 0; i--) {
        if (matrix[i][i] == 0) { // Avoid division by zero
            cout << "Back substitution failed: zero pivot at row " << i << endl;
            return {};
        }
        solution[i] = matrix[i][nCols - 1]; // Start with b value
        for (int j = i + 1; j < nRows; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i]; // Normalize
    }
    return solution;
}

// Perform Gaussian Elimination (Calls Other Functions)
vector<long double> Matrix::gaussianElimination() {
    if (!basicPivoting()) {
        cout << "Pivoting Failed: Singular matrix detected." << endl;
        return {};
    }
    forwardElimination();
    return backSubstitution();
}
