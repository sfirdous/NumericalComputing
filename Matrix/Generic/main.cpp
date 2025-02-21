#include "Matrix.hpp"
using namespace std;

int main() {
    // Matrix<int> A(2, 2);
    // Matrix<int> C(A);
    // std::cout << A << std::endl;
    // std::cout << C << std::endl;

    Matrix<int> A(2,2);
    cout << A.getRow() << A.getCol() << endl;

    return 0;
}
