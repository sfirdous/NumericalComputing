#include "Matrix.hpp"

// Operator Overloads
Matrix Matrix::operator+(const Matrix &B) const {
    return this->add(B);
}

Matrix Matrix::operator-(const Matrix &B) const {
    return this->sub(B);
}

Matrix Matrix::operator*(const Matrix &B) const {
    return this->mul(B);
}


// Overload << operator
std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    for (int i = 0; i < m.getRow(); ++i) {
        for (int j = 0; j < m.getCol(); ++j) {
            os << m.getValue(i, j) << "\t";
        }
        os << "\n";
    }
    return os;
}