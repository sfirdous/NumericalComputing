#include "Matrix.hpp"
using namespace;

template <typename T>
Matrix<T>::Matrix(int r, int c)
{
    nRows = r;
    nCols  = c;

    //Allocate meomery for row pointers
    matrix = new T *[nRows];

    //Allocate meomery for column in each row
    for(int i = 0 ; i < nRows ; ++i){
        matrix[i] = new T [nCols];
    }

    setValues();

}

template <typename T>
Matrix<T>::Matrix(Matrix<T>& other)
{
    nRows = other.getRow();
    nCols = other.getCol();

    matrix = new T*[nRows];

    for(int i = 0; i < nRows;++i)
        matrix[i] = new T [nCols];

    for(int i = 0 ; i < nRows ; ++i)
    {
        for(int j = 0 ; j < nCols ; ++j)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }

}

template <typename T>
void Matrix<T>::setValues()
{
    for(int i = 0 ; i < nRows ; ++i)
    {
        for(int j = 0 ; j < nCols ; ++j)
        {
            cin >> matrix[i][j];
        }
    }
}


//Operator overloading defination
std::ostream& operator<<(std::ostream& os , Matrix<T>& m){
    for(int i = 0 ; i < nRows ; ++i)
    {
        for(int j = 0 ; j < nCols ; ++j)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }


    return os;
}


template <typename T>
Matrix<T>::~Matrix()
{
    for(int i = 0 ; i < nRows ; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}