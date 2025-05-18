#include "Matrix.hpp"

std::vector<long double> Matrix::gaussElimination()
{
    Matrix temp(*this);
    rowReduction(temp);
    return backSubstitution(temp);
}

std::vector<long double> Matrix::backSubstitution(Matrix& temp)
{
    std::vector<long double> answer(temp.nRows, 0);

    for (int r = temp.nRows - 1; r >= 0; --r)
    {
        answer[r] = temp.matrix[r][temp.nCols - 1]; // RHS value

        for (int c = r + 1; c < temp.nCols - 1; ++c)
            answer[r] -= temp.matrix[r][c] * answer[c];

        if (std::fabs(temp.matrix[r][r]) < 1e-40)
            throw std::runtime_error("Zero diagonal during back substitution");

        answer[r] /= temp.matrix[r][r];
    }

    return answer;
}