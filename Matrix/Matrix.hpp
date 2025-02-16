#include <iostream>

template <class T>
class Matrix
{
private:
    int rowSize;
    int colSize;
    T **matrix;

public:
    //Constructors
    Matrix();
    Matrix(int r,int c);
    Matrix(Matrix& matrix);
    Matrix(string filename);

    //Setter's and Getter's
    void setRow(int r) {this->rowSize = r;}
    int getRow(){return rowSize;}

    void setCol(int c){this->colSize = c;}
    int getCol(){return colSize;}

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
