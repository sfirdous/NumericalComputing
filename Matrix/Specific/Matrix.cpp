#include "Matrix.hpp"
#include <iostream>

using namespace std;

// Default Constructor
Matrix::Matrix() {
    cout << "Pass the dimensions of matrix as arguments" << endl;
}

// Constructor for user input
Matrix::Matrix(int r, int c) {
    setRow(r);
    setCol(c);
    allocateMemory();
    
}

// Copy Constructor
Matrix::Matrix(const Matrix &other) {
    setRow(other.getRow());
    setCol(other.getCol());
    allocateMemory();

    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

// Constructor to read from file
Matrix::Matrix(std::string filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Cannot open file" << endl;
        return;
    } else {
        file >> nRows;
        file >> nCols;
        allocateMemory();

        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                file >> matrix[i][j];
            }
        }
    }
}

// Destructor
Matrix::~Matrix() {
    for (int i = 0; i < nRows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}




