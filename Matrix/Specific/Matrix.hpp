
#ifndef MATRIX_HPP
#define MATRIX_HPP

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
    // Constructor
    Matrix();
    Matrix(int r, int c);
    Matrix(int r,int c,long double value);
    Matrix(const Matrix& other);
    Matrix(std::string filename);

    //Getters
    int getNRow(){ return nRows;}
    int getNCol(){return nCols;}
    long double getValue(int i, int j){return matrix[i][j];}
    long double** getMatrix(){return matrix;}

    //Setters
    void setNRow(int r){nRows = r;}
    void setNCol(int c){nCols = c;}
    void setValue(int i,int j,long double value){matrix[i][j] = value;}
    void setValues();

    //Memory Allocator function
    void allocateMemory();

    //Method to swap rows
    void swapRows(int r,int index);

    //Properties
    bool isIdentity();
    bool isSymmetric();


    //Guassian Elimination
    std::vector<long double> gaussElimination();
    std::vector<long double> backSubstitution(Matrix& temp);
    friend void pivoting(Matrix& temp,int currentRow);
    friend void rowReduction(Matrix& temp);

    //LUDecomposition
    std::vector<Matrix> DolittleLUDecomposition();
    std::vector<Matrix> CroutLUDecomposition();
    Matrix CholeslyLUDecomposition();

    //Iterative Methods helper functions
    bool isDiagonallyDominant();
    bool isDiagonallyDominantRow(int r);
    bool makeDiagonallyDominant();
    int getDiagonallyDominantRowFor(int r);

    //Iterative Methods
    std::vector<long double> gaussJacobi(long double tolerance);
    std::vector<long double> gaussSeidel(long double tolerance);

  
    //friend functions
    friend std::ostream& operator<<(std::ostream& out,Matrix& M);

    // Destructor
    ~Matrix();
};
#endif