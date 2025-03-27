#include "Matrix.hpp"
#include <vector>
#include <iostream>
#include <cmath> 


std::vector<long double> Matrix::gaussSeidel(int maxIterations, long double tolerance) {
    std::vector<long double> x(nRows, 0.0); 
    std::vector<long double> prev_x(nRows, 0.0);
    
    if (!isDiagonallyDominant()) {
        std::cout << "Matrix is not diagonally dominant\n";
        // if(!makeDiagonallyDominant())
        // {
        //     std::cout << "Matrix could not be made diagonally dominant\n";
        //     return{};
        // }
    }

    int iter = 0;
    while(1){
        for (int i = 0; i < nRows; i++) {
            long double sum = 0.0;

            for (int j = 0; j < nCols - 1; j++) {
                if (j != i) {
                    sum += matrix[i][j] * x[j]; // Using updated values immediately
                }
            }

            x[i] = (matrix[i][nCols - 1] - sum) / matrix[i][i]; // Update current variable
        }

        // Check for convergence 
        long double error = 0.0;
        for (int i = 0; i < nRows; i++) {
            error += std::fabs(x[i] - prev_x[i]);
        }
        if (error < tolerance) {
            std::cout << "Gauss-Seidel converged in " << iter + 1 << " iterations.\n";
            return x;
        }

        prev_x = x; // Store previous iteration values
    }

    std::cout << "Gauss-Seidel did not converge within " << maxIterations << " iterations.\n";
    return x; // Return the last computed values 
}
