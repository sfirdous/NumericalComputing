#include "Matrix.hpp"

template <typename T>
Matrix<T>::Matrix()
{
    std::cout << "Pass Dimensions of Matrix as Arguments" << std::endl;
}

template <typename T>
Matrix<T>::Matrix(int r,int c)
{
    nRows = r;
    nCols = c;
}


