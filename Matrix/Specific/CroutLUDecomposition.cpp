#include "Matrix.hpp"

std::vector<Matrix> Matrix::CroutLUDecomposition()
{
    if (nRows != nCols - 1)
    {
        std::cout << "Matrix not square" << std::endl;
        exit(1);
    }

    int n = nRows;
    std::vector<Matrix> result;

    Matrix L(n, n);
    Matrix U(n, n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            U.matrix[i][j] = (i == j) ? 1.0 : 0.0;
            L.matrix[i][j] = 0.0;
        }
    }

    for (int j = 0; j < n; ++j)
    {
        for (int i = j; i < n; ++i)
        {
            long double sum = 0.0;
            for (int k = 0; k < j; ++k)
                sum += L.matrix[i][k] * U.matrix[k][j];
            L.matrix[i][j] = matrix[i][j] - sum;
        }
        
        for (int i = j+1;i<n;++i)
        {
           long double sum = 0.0;
            for (int k = 0; k < j; ++k)
                sum += L.matrix[j][k] * U.matrix[k][i];
            U.matrix[j][i] = (matrix[j][i] - sum) / L.matrix[j][j];
        }
    }
    result.push_back(L);
    result.push_back(U);

    return result;
}
