#include "Matrix.hpp"
#include <iostream>
#include <vector>
#include <cmath>

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

bool Matrix::makeDiagonallyDominant()
{
    for (int r = 0; r < nRows; r++)
    {
        double diagonal = fabs(matrix[r][r]);
        double rowSum = 0.0;

        for (int c = 0; c < nRows; c++)
        {
            if (c != r)
            {
                rowSum += fabs(matrix[r][c]);
            }
        }

        if (diagonal <= rowSum)
        { 
            int index = getDiagonallyDominantRow(r);
            if (index == -1)
                return false;
            else
                std::swap(matrix[r], matrix[index]);
        }
    }
    return true;
}

int Matrix::getDiagonallyDominantRow(int r)
{
    for (int i = r + 1; i < nRows; i++)
    {
        int rowSum = 0;
        for (int c = 0; c < nRows; c++)
        {
            if (r != c)
            {
                rowSum += fabs(matrix[i][c]);
            }
            if (fabs(matrix[i][i] >= rowSum))
            {
                return i;
            }
        }
    }
    return -1;
}

