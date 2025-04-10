#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

class Matrix
{
private:
    int nRows;
    int nCols;
    long double **matrix;

public:
    // Constructors
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix &other);
    Matrix(std::string filename); // Assumes file-based initialization

    // Setters and Getters
    void setRow(int r) { this->nRows = r; }
    int getRow() const { return nRows; }

    void setCol(int c) { this->nCols = c; }
    int getCol() const { return nCols; }

    void setValues(); // For manual entry
    long double getValue(int i, int j) const { return matrix[i][j]; }
    void setValue(int i, int j, long double value) { matrix[i][j] = value; }

    // Memory Management
    void allocateMemory(); // Allocates matrix with current nRows, nCols
    ~Matrix();             // Destructor for deallocation

    // Matrix Operations
    Matrix add(const Matrix &B) const;
    Matrix sub(const Matrix &B) const;
    Matrix mul(const Matrix &B) const;

    // Operator Overloading
    Matrix operator+(const Matrix &B) const;
    Matrix operator-(const Matrix &B) const;
    Matrix operator*(const Matrix &B) const;

    // Matrix Properties
    bool isIdentity();
    bool isSymmetric();
    bool isDiagonallyDominant();

    // Gaussian Elimination
    long double** rowReduction();
    std::vector<long double> backSubstitution(long double** reducedMat);
    std::vector<long double> gaussianElimination();                           // Solves augmented matrix Ax = b

    // LU Decomposition
    void DolittlesLUDecomposition(Matrix &L, Matrix &U);
    void CroutsLUDecomposition(Matrix &L, Matrix &U);
    void CholeskyLUDecomposition(Matrix &L);
    std::vector<long double> forwardSolve();                                  // For LU solvers
    std::vector<long double> backwardSolve(const std::vector<long double> &y);
    std::vector<long double> solveLU(Matrix &L, Matrix &U);                   // Solves LUx = b

    // Iterative Solvers
    std::vector<long double> gaussSeidel(int maxIterations, long double tolerance);
    std::vector<long double> gaussJacobi(int maxIterations, long double tolerance);

    // Diagonal Dominance Tools
    bool makeDiagonallyDominant();                                            // Tries to rearrange rows
    int getDiagonallyDominantRow(int r);                                      // Finds better pivot row

    // Output
    friend std::ostream &operator<<(std::ostream &os, const Matrix &m);       // To print matrix easily
};

#endif
