#include "Matrix.h"

template <typename T>
bool Matrix<T>::isIdentity(Matrix<T>& A)
{
    int rows = A.getRow();
    int cols = A.getCol();

    if(rows != cols)
        return false;
    for(int i = 0 ; i < rows ;++i)
    {
        for(int j = 0; j < col;++j)
        {
            T value = A.getValue(i,j);
            if(i == j && value != 1)
                return false;
            else if(i != j && value != 0)
                return false;
        }
    }

    return true;
}

template <typename T>
bool Matrix<T>::isSymmetric(Matrix<T>& A)
{
    int rows = A.getRow();
    int cols = A.getCol();

    if(rows != cols)
        return false;
    for(int i = 0 ; i < rows ;++i)
    {
        for(int j = i+1; j < col;++j)
        {
            
            if(A.getValue(i,j) != A.getValue(j,i))
                return false;
        }
    }

    return true;
}