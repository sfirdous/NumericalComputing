#include <iostream>

template <class T>
class Matrix
{
private:
    int nRows;
    int nCols;
    T **matrix;

public:
    //Constructors
    Matrix(int r,int c);
    Matrix(Matrix& matrix);
    Matrix(string filename);

    //Setter's and Getter's
    void setRow(int r) {this->nRows = r;}
    int getRow(){return nRows;}

    void setCol(int c){this->nCols = c;}
    int getCol(){return nCols;}


    //Accept values of matrix from user
    void setMatrix();

    //Operations using methods
    Matrix add(Matrix& B);
    Matrix sub(Matrix& B);
    Matrix mul(Matrix& B);

    //Operations using operator overloading
    Matrix operator+(Matrix& B);
    Matrix operator-(Matrix& B);
    Matrix operator*(Matrix& B);

    //Property checking functions
    bool isIdentity(Matrix& A);
    bool isSymmetric(Matrix& A);

    //Destructor
    ~Matrix();
};
