#include "Matrix.hpp"

Matrix Matrix::CholeslyLUDecomposition()
{
    if (!this->isSymmetric())
        std::cout << "Matrix not Symmertric" << std::endl;

    Matrix L(nRows, nRows, 0.0);

    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            long double sum = 0.0;
            for (int k = 0; k < j; ++k)
                sum += L.matrix[i][k] * L.matrix[j][k];

            if (i == j)
                L.matrix[i][j] = sqrt(matrix[i][i] - sum);
            else
                L.matrix[i][j] = (matrix[i][j] - sum) / L.matrix[j][j];
        }
    }

    return L;
}
