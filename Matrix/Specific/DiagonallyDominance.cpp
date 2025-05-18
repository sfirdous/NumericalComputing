#include "Matrix.hpp"

bool Matrix::isDiagonallyDominant()
{
    for(int i = 0; i < nRows;++i)
    {
        if(!isDiagonallyDominantRow(i))
            return false;
    }
    return true;
}
bool Matrix::isDiagonallyDominantRow(int r)
{
    long double sum = 0.0;
    for(int j = 0 ; j < nRows ;++j)
    {
        if(r!=j)
            sum += fabs(matrix[r][j]);
    }
    if(matrix[r][r] < sum)
        return false;
    
    return true;
}

bool Matrix::makeDiagonallyDominant()
{
    for(int i = 0; i < nRows ; ++i)
    {
        if(!isDiagonallyDominantRow(i))
        {
            int new_i = getDiagonallyDominantRowFor(i);
            if(new_i == -1)
                return false;
            swapRows(i,new_i);
        }
    }
    return true;
}

int Matrix::getDiagonallyDominantRowFor(int r)
{
    for(int i = r+1 ; i < nRows ; ++i)
    {
        long double sum = 0.0;
        for(int j = 0; j < nRows;++j)
        {
            if(r!=j)
                sum += matrix[i][j];
        }
        if(fabs(matrix[i][r]) >= sum)
            return i;
    }
    return -1;
}