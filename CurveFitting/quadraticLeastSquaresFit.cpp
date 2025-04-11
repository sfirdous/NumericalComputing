#include "CurveFit.hpp"
#include <fstream>

void CurveFit::quadraticLeastSquaresFit() {
    long double S_x = 0, S_x2 = 0, S_x3 = 0, S_x4 = 0;
    long double S_y = 0, S_xy = 0, S_x2y = 0;

    for (int i = 0; i < n; ++i) {
        long double x = x_i[i];
        long double y = f_x_i[i];
        S_x += x;
        S_x2 += x * x;
        S_x3 += x * x * x;
        S_x4 += x * x * x * x;
        S_y += y;
        S_xy += x * y;
        S_x2y += x * x * y;
    }


    std::string filename = "/workspaces/NumericalComputing/CurveFitting/quad_matrix.txt";

    std::ofstream fout(filename, std::ios::trunc);  
    if (!fout) {
        std::cerr << "Failed to open file!" << std::endl;
        return;
    }
    
    fout << 3 << " " << 3 << "\n";

    fout << S_x4 << " " << S_x3 << " " << S_x2 << " " << S_x2y << "\n";
    fout << S_x3 << " " << S_x2 << " " << S_x  << " " << S_xy  << "\n";
    fout << S_x2 << " " << S_x  << " " << n    << " " << S_y   << "\n";

    fout.close();

    Matrix A(filename);

    std::vector<long double> result = A.gaussianElimination();
    resultstruct.a = result[0];
    resultstruct.b = result[1];
    resultstruct.c = result[2];
}
