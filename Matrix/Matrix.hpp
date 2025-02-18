#include <iostream>

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
    Matrix(string filename);

    //Setter's and Getter's
    void setRow(int r) {this->nRows = r;}
    int getRow(){return nRows;}

    void setCol(int c){this->nCols = c;}
    int getCol(){return nCols;}

    void setValues();
  

    //Operations using methods
    Matrix<T> add(Matrix<T>& B);
    Matrix<T> sub(Matrix<T>& B);
    Matrix<T> mul(Matrix<T>& B);

    //Operations using operator overloading
    Matrix<T> operator+(Matrix<T>& B);
    Matrix<T> operator-(Matrix<T>& B);
    Matrix<T> operator*(Matrix<T>& B);

    //Property checking functions
    bool isIdentity(Matrix<T>& A);
    bool isSymmetric(Matrix<T>& A);

    //Destructor
    ~Matrix();
};
