#include "Matrix.hpp"
using namespace std;

//Default Constructor
template <typename T>
Matrix<T>::Matrix()
{
    cout << "Pass the dimensions of matrix as arguments" << endl;
} 


//Constructor that read matrices through command line
template <typename T>
Matrix<T>::Matrix(int r, int c)
{
    setRow(r);
    setCol(c);
    allocateMeomery();
    cout << "Enter values of Matrix" << endl;
    setValues();
}

//Copy Constructor
template <typename T>
Matrix<T>::Matrix(Matrix<T> &other)
{
    setRow(other.getRow());
    setCol(other.getCol());
    allocateMeomery();

    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

//Constructor that reads file from file
template <typename T>
Matrix<T>::Matrix(std::string filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "Error : Connot open file" << endl;
    }
    else
    {
        file >> nRows;
        file >> nCols;

        allocateMeomery();

        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                file >> matrix[i][j];
            }
        }
    }
}


template <typename T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < nRows; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}


