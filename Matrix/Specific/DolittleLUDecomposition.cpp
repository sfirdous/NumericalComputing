#include "Matrix.hpp"

std::vector<Matrix> Matrix::DolittleLUDecomposition()
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
            L.matrix[i][j] = (i == j) ? 1.0 : 0.0;
            U.matrix[i][j] = 0.0;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            long double sum = 0.0;
            for (int k = 0; k < i; ++k)
                sum += L.matrix[i][k] * U.matrix[k][j];
            U.matrix[i][j] = matrix[i][j] - sum;
        }
        
        for (int j = i+1;j<n;++j)
        {
           long double sum = 0.0;
            for (int k = 0; k < i; ++k)
                sum += L.matrix[j][k] * U.matrix[k][i];
            L.matrix[j][i] = (matrix[j][i] - sum) / U.matrix[i][i];
        }
    }
    result.push_back(L);
    result.push_back(U);

    return result;
}
