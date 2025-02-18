#include "Matrix.hpp"
using namespace;

template <class T>
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

    setMatrix();

}


template <class T>
void Matrix<T>::setMatrix()
{
    for(int i = 0 ; i < nRows ; ++i)
    {
        for(int j = 0 ; j < nCols ; ++j)
        {
            cin >> matrix[i][j];
        }
    }
}


template <class T>
Matrix<T>::~Matrix()
{
    for(int i = 0 ; i < nRows ; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}