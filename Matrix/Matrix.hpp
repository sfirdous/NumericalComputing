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
    Matrix(Matrix<T>& matrix);
    Matrix(string filename);

    //Setter's and Getter's
    void setRow(int r) {this->nRows = r;}
    int getRow(){return nRows;}

    void setCol(int c){this->nCols = c;}
    int getCol(){return nCols;}

    void setValues();
    T** getValues(){return matrix;}

    //Operations using methods
    Matrix add(Matrix<T>& B);
    Matrix sub(Matrix<T>& B);
    Matrix mul(Matrix<T>& B);

    //Operations using operator overloading
    Matrix operator+(Matrix<T>& B);
    Matrix operator-(Matrix<T>& B);
    Matrix operator*(Matrix<T>& B);

    //Property checking functions
    bool isIdentity(Matrix<T>& A);
    bool isSymmetric(Matrix<T>& A);

    //Destructor
    ~Matrix();
};
