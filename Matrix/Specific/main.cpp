#include "Matrix.hpp"

int main() {
    Matrix A(2, 2);
    std::cout << "Enter Matrix A" << std::endl;
    A.setValues();
    Matrix B(2, 2);
    std::cout << "Enter Matrix B" << std::endl;
    B.setValues();

    Matrix C = A + B;
    Matrix D = A - B;
    Matrix E = A * B;

    std::cout << "Matrix A:\n" << A;
    std::cout << "Matrix B:\n" << B;
    std::cout << "A + B:\n" << C;
    std::cout << "A - B:\n" << D;
    std::cout << "A * B:\n" << E;

    Matrix F("/workspaces/NumericalComputing/Matrix/matrices/int_49x50.txt");
    std::cout << F;

    Matrix G("/workspaces/NumericalComputing/Matrix/matrices/int_49x50.txt");
    std::cout << G;
    
    Matrix X = F + G;
    std::cout << "F + G:\n" << X;

    return 0;
}
