
#include <iostream>
#include <fstream>
#include <vector>
class Matrix {
private:
    int nRows;
    int nCols;
    int **matrix;

public:
    // Constructors
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix &other);
    Matrix(std::string filename);

    // Setters and Getters
    void setRow(int r) { this->nRows = r; }
    int getRow() const { return nRows; }

    void setCol(int c) { this->nCols = c; }
    int getCol() const { return nCols; }

    void setValues();
    int getValue(int i, int j) const { return matrix[i][j]; }

    // Operations
    Matrix add(const Matrix &B) const;
    Matrix sub(const Matrix &B) const;
    Matrix mul(const Matrix &B) const;

    // Operator Overloading
    Matrix operator+(const Matrix &B) const;
    Matrix operator-(const Matrix &B) const;
    Matrix operator*(const Matrix &B) const;

    // Memory Management
    void allocateMemory();

    // Properties
    bool isIdentity() const;
    bool isSymmetric() const;

    // Gaussian Elimination 
    void basicPivoting();
    void forwardElimination();
    std::vector<double> backSubstitution();
    std::vector<double> gaussianElimination();

    // Destructor
    ~Matrix();

    // Friend Function
    friend std::ostream &operator<<(std::ostream &os, const Matrix &m);
};


