void LUDecomposition(Matrix &L, Matrix &U) const {
    if (nRows != nCols) {
        std::cout << "Matrix must be square for LU decomposition." << std::endl;
    }

    // Initialize L and U matrices
    L = Matrix(nRows, nCols);
    U = Matrix(nRows, nCols);

    // Set up L as an identity matrix and U as a zero matrix initially
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            if (i == j) L.matrix[i][j] = 1; // Diagonal elements of L are 1
            else L.matrix[i][j] = 0;
            U.matrix[i][j] = 0;
        }
    }

    // Perform LU decomposition
    for (int i = 0; i < nRows; i++) {
        // Compute the upper triangular matrix U
        for (int k = i; k < nCols; k++) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L.matrix[i][j] * U.matrix[j][k]);
            }
            U.matrix[i][k] = matrix[i][k] - sum;
        }

        // Compute the lower triangular matrix L
        for (int k = i + 1; k < nRows; k++) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L.matrix[k][j] * U.matrix[j][i]);
            }
            L.matrix[k][i] = (matrix[k][i] - sum) / U.matrix[i][i];
        }
    }
}

