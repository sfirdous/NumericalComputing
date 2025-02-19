#include "Matrix.hpp"

template <typename T>
Matrix<T> Matrix<T>::add(Matrix<T>& B)
{
   Matrix<T> result(nRows,nCols);

   for (int i = 0; i < nRows; i++)
   {
    for (int j = 0; i < nCols; j++)
    {
        result.matrix[i][j] = this->matrix[i][j] + B.getValue(i,j);
    }
   }

   return result;
   
}

template <typename T>
Matrix<T> Matrix<T>::sub(Matrix<T>& B)
{
    Matrix<T> result(nRows,nCols);

    for (int i = 0; i < nRows; i++)
    {
     for (int j = 0; i < nCols; j++)
     {
         result.matrix[i][j] = this->matrix[i][j] - B.getValue(i,j);
     }
    }
 
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::mul(Matrix<T>& B)
{
    Matrix<T> result(this->nCols,B.getRow());

    for(int i = 0 ; i < this->nRows ; ++i)
    {
        for(int j = 0 ; j < B.getCol() ; ++j)
        {
            result.matrix[i][j] = 0;
            for (int k = 0; k < this->nCols; k++)
            {
                result.matrix[i][j] += this->matrix[i][k] * B.getValue(k,j);
            }
            
        }
    }

    return result;
}


template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T>& B)
{
    return this->add(B);
}

template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T>& B)
{
    return this->sub(B);
}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& B)
{
   return this->mul(B);
}