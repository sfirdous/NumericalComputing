#include "Matrix.hpp"

std::vector<long double> Matrix::gaussSeidel(long double tolerance)
{
    if(!isDiagonallyDominant()){
        if(!makeDiagonallyDominant()){
            std::cout << "Coefficient Matrix could not be made diagonally dominant" << std::endl;
            exit(1);
        }
    }

    std::vector<long double> x(nRows,0.0);
    std::vector<long double> prev_x(nRows,0.0);

    int iter = 0;
    while(1)
    {
        for(int i = 0 ; i < nRows ; ++i)
        {
            long double sum = 0.0;
            for(int j = 0 ; j < nRows ; ++j)
                if(i!=j)
                    sum += matrix[i][j] * x[j];
            x[i] = (matrix[i][nCols -1] - sum) / matrix[i][i];
        }
        iter++;

        long double error = 0;
        for(int i = 0 ; i < nRows ; ++i)
            error += fabs(x[i] - prev_x[i]);

        if(error < tolerance)
            break;
            
        prev_x = x;
    }

    return x;
}
