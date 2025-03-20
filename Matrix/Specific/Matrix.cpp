#include "Matrix.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Default Constructor
Matrix::Matrix() {
    cout << "Pass the dimensions of matrix as arguments" << endl;
    nRows = 0;
    nCols = 0;
    matrix = nullptr;
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
        cout << "Error: Cannot open file " << filename << endl;
        nRows = 0;
        nCols = 0;
        matrix = nullptr;
        return;
    }
    
    int rows, cols;
    file >> rows >> cols; // Read the number of rows and columns (excluding b)

    nRows = rows;
    nCols = cols + 1; // Add one extra column for b

    allocateMemory(); // Allocate memory properly

    // Read matrix values from the file
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            if (!(file >> matrix[i][j])) { // Check if reading fails
                cout << "Error: Insufficient data in file." << endl;
                return;
            }
        }
    }

    file.close(); // Close the file
}

// Destructor
Matrix::~Matrix() {
    if (matrix) {
        for (int i = 0; i < nRows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}




