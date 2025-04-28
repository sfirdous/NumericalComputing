#include "Matrix.hpp"
using namespace std;

int main() {

    Matrix<int> A(2,2);
    cout << A.getRow() << A.getCol() << endl;

    return 0;
}
