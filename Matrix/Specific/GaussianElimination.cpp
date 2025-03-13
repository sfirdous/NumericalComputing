#include "Matrix.hpp"
#include <vector>


bool Matrix::basicPivoting() {
    for (int i = 0; i < nRows; i++) {
        if (matrix[i][i] == 0) {
            bool swapped = false;
            for (int k = i + 1; k < nRows; k++) {
                if (matrix[k][i] != 0) {
                    std::swap(matrix[i], matrix[k]); 
                    swapped = true;
                    break;
                }
            }
            if (!swapped) {
                return false; 
            }
        }
    }
    return true; 
}


void Matrix::forwardElimination() {
    for (int i = 0; i < nRows; i++) {
        for (int k = i + 1; k < nRows; k++) {
            long double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < nCols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}

std::vector<double> Matrix::backSubstitution() {
    std::vector<double> solution(nRows, 0);
    for (int i = nRows - 1; i >= 0; i--) {
        solution[i] = matrix[i][nCols - 1];
        for (int j = i + 1; j < nRows; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }
    return solution;
}

std::vector<long double> Matrix::gaussianElimination() {
    Matrix tempMatrix(*this); // Copy the original matrix
    if(!tempMatrix.basicPivoting())
    {
        std::cout << "Pivoting Failed" << std::endl;
        exit(1);
    }
    tempMatrix.forwardElimination();
    return tempMatrix.backSubstitution();
}
