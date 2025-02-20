#include "Matrix.hpp"

int main() {
    Matrix A(2, 2);
    A.setValues();
    Matrix B(2, 2);
    B.setValues();

    Matrix C = A + B;
    Matrix D = A - B;
    Matrix E = A * B;

    std::cout << "Matrix A:\n" << A;
    std::cout << "Matrix B:\n" << B;
    std::cout << "A + B:\n" << C;
    std::cout << "A - B:\n" << D;
    std::cout << "A * B:\n" << E;

    return 0;
}
