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
        cout << "Error: Cannot open file" << endl;
        nRows = 0;
        nCols = 0;
        matrix = nullptr;
        return;
    }
    
    file >> nRows >> nCols;
    allocateMemory();
    
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            file >> matrix[i][j];
        }
    }
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

// Allocate memory for matrix
void Matrix::allocateMemory() {
    matrix = new int *[nRows];
    for (int i = 0; i < nRows; ++i) {
        matrix[i] = new int[nCols](); // Initialize to zero
    }
}

// Set values from user input
void Matrix::setValues() {
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// Addition
Matrix Matrix::add(const Matrix &B) const {
    if (nRows != B.getRow() || nCols != B.getCol()) {
        cout << "Error: Matrix dimensions do not match for addition" << endl;
        return Matrix();
    }
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
    if (nRows != B.getRow() || nCols != B.getCol()) {
        cout << "Error: Matrix dimensions do not match for subtraction" << endl;
        return Matrix();
    }
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
    if (nCols != B.getRow()) {
        cout << "Error: Matrix dimensions do not match for multiplication" << endl;
        return Matrix();
    }
    Matrix result(nRows, B.getCol());
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < B.getCol(); ++j) {
            for (int k = 0; k < nCols; k++) {
                result.matrix[i][j] += this->matrix[i][k] * B.getValue(k, j);
            }
        }
    }
    return result;
}

// Operator Overloads
Matrix Matrix::operator+(const Matrix &B) const {
    return this->add(B);
}

Matrix Matrix::operator-(const Matrix &B) const {
    return this->sub(B);
}

Matrix Matrix::operator*(const Matrix &B) const {
    return this->mul(B);
}

// Check if matrix is Identity
bool Matrix::isIdentity() const {
    if (nRows != nCols)
        return false;

    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0))
                return false;
        }
    }
    return true;
}

// Check if matrix is Symmetric
bool Matrix::isSymmetric() const {
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

// Overload << operator
std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    for (int i = 0; i < m.getRow(); ++i) {
        for (int j = 0; j < m.getCol(); ++j) {
            os << m.getValue(i, j) << "\t";
        }
        os << "\n";
    }
    return os;
}
