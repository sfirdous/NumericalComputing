
#include <iostream>
#include <fstream>
#include <vector>
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
    Matrix(std::string filename);

    // Setters and Getters
    void setRow(int r) { this->nRows = r; }
    int getRow() const { return nRows; }

    void setCol(int c) { this->nCols = c; }
    int getCol() const { return nCols; }
    

    void setValues();
    long double getValue(int i, int j) const { return matrix[i][j]; }
    void setValue(int i ,int j,long double value)  {matrix[i][j] = value;}

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
    bool isIdentity();
    bool isSymmetric();
    bool isDiagonallyDominant();

    // Gaussian Elimination
    std::vector<std::vector<long double>> rowReduction();
    std::vector<long double> backSubstitution(std::vector<std::vector<long double>> &reducedMat);
    std::vector<long double> gaussianElimination();

    // LU Decomposition
    std::vector<long double> forwardSolve();
    std::vector<long double> backwardSolve(const std::vector<long double> &y);
    std::vector<long double> solveLU(Matrix &L, Matrix &U);
    void DolittlesLUDecomposition(Matrix &L, Matrix &U);
    void CroutsLUDecomposition(Matrix &L, Matrix &U);
    void CholeskyLUDecomposition(Matrix &L);


    //Iterative Methods
    std::vector<long double> gaussSeidel(int maxIterations, long double tolerance);
    std::vector<long double> gaussJacobi(int maxIterations, long double tolerance); 

    // Friend Function
    friend std::ostream &operator<<(std::ostream &os, const Matrix &m);

    
    bool makeDiagonallyDominant();
    int getDiagonallyDominantRow(int r);

    // Destructor
    ~Matrix();

};
