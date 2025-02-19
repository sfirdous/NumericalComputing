#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <string.h>
#include <fstream>

template <typename T>
class Matrix
{
private:
    int nRows;
    int nCols;
    T **matrix;

public:
    //Constructors
    Matrix(int r,int c);
    Matrix(Matrix<T>& other);
    Matrix(std::string filename);

    //Setter's and Getter's
    void setRow(int r) {this->nRows = r;}
    int getRow(){return nRows;}

    void setCol(int c){this->nCols = c;}
    int getCol(){return nCols;}

    void setValues();
    T getValue(int i,int j){return matrix[i][j];}
  

    //Operations using methods
    Matrix<T> add(Matrix<T>& B);
    Matrix<T> sub(Matrix<T>& B);
    Matrix<T> mul(Matrix<T>& B);

    //Operations using operator overloading
    Matrix<T> operator+(Matrix<T>& B);
    Matrix<T> operator-(Matrix<T>& B);
    Matrix<T> operator*(Matrix<T>& B);

    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os,Matrix<U>& m);

    //Property checking functions
    bool isIdentity(Matrix<T>& A);
    bool isSymmetric(Matrix<T>& A);

    //Destructor
    ~Matrix();
};

#include "Matrix.cpp"

#endif