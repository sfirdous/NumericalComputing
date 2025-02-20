#include "Matrix.hpp"

template <typename T>
void Matrix<T>::setValues()
{
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::allocateMeomery()
{
   
    // Allocate meomery for row pointers
    matrix = new T *[nRows];

    // Allocate meomery for column in each row
    for (int i = 0; i < nRows; ++i)
    {
        matrix[i] = new T[nCols];
    }
}

