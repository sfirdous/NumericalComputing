#include "Matrix.hpp"

void pivoting(Matrix &temp, int currentRow)
{
    int r = temp.getNRow();
    int c = temp.getNCol();

    int maxRow = currentRow;
    for (int j = currentRow + 1; j < r; ++j)
    {
        if (std::fabs(temp.getValue(j, currentRow)) > std::fabs(temp.getValue(maxRow, currentRow)))
            maxRow = j;
    }

    if (maxRow != currentRow)
    {
        for (int j = 0; j < c; ++j)
            std::swap(temp.matrix[currentRow][j], temp.matrix[maxRow][j]);
    }
}

void rowReduction(Matrix &temp)
{
    for (int i = 0; i < temp.nRows; ++i)
    {
        pivoting(temp, i);

        long double pivot = temp.matrix[i][i];
        if (std::fabs(pivot) < 1e-40)
            throw std::runtime_error("Zero or near-zero pivot encountered");

        // Normalize pivot row
        for (int j = i; j < temp.nCols; ++j)
            temp.matrix[i][j] /= pivot;

        // Eliminate below
        for (int i_ = i + 1; i_ < temp.nRows; ++i_)
        {
            long double e = temp.matrix[i_][i];
            for (int j = i; j < temp.nCols; ++j)
                temp.matrix[i_][j] -= temp.matrix[i][j] * e;
        }
    }
}