#include "Matrix.hpp"
using namespace std;

template <typename T>
Matrix<T>::Matrix(int r, int c)
{
    nRows = r;
    nCols  = c;

    //Allocate meomery for row pointers
    matrix = new T *[nRows];

    //Allocate meomery for column in each row
    for(int i = 0 ; i < nRows ; ++i){
        matrix[i] = new T [nCols];
    }

    cout << "Enter values of Matrix" << endl;
    setValues();

}

template <typename T>
Matrix<T>::Matrix(Matrix<T>& other)
{
    nRows = other.getRow();
    nCols = other.getCol();

    matrix = new T*[nRows];

    for(int i = 0; i < nRows;++i)
        matrix[i] = new T [nCols];

    for(int i = 0 ; i < nRows ; ++i)
    {
        for(int j = 0 ; j < nCols ; ++j)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }

}

template <typename T>
void Matrix<T>::setValues()
{
    for(int i = 0 ; i < nRows ; ++i)
    {
        for(int j = 0 ; j < nCols ; ++j)
        {
            cin >> matrix[i][j];
        }
    }
}


//Operator overloading defination

template <typename T>
std::ostream& operator<<(std::ostream& os,Matrix<T>& m) {
    for (int i = 0; i < m.getRow(); ++i) {
        for (int j = 0; j < m.getCol(); ++j) {
            os << m.getValue(i, j) << "\t";
        }
        os << "\n";
    }
    return os;
}

template <typename T>
Matrix<T>::~Matrix()
{
    for(int i = 0 ; i < nRows ; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

