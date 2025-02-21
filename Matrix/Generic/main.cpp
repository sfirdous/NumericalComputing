#include "Matrix.hpp"

int main() {
    Matrix<int> A(2, 2);
    Matrix<int> C(A);
    std::cout << A << std::endl;
    std::cout << C << std::endl;
    return 0;
}
