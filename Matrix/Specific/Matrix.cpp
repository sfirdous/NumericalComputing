#include "Matrix.hpp"
using namespace std;

// Constructor Definations
Matrix::Matrix()
{
    nRows = 0;
    nCols = 0;
    matrix = nullptr;
}

Matrix::Matrix(int r, int c)
{
    nRows = r;
    nCols = c;
    allocateMemory();
}

Matrix::Matrix(int r,int c,long double value)
{
    nRows = r;
    nCols = c;
    allocateMemory();

    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            matrix[i][j] = value;
        }
    }
}

Matrix::Matrix(const Matrix &other)
{
    nRows = other.nRows;
    nCols = other.nCols;
    allocateMemory();
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

Matrix::Matrix(string filename)
{

    ifstream file(filename);

    if (!file)
    {
        nRows = 0;
        nCols = 0;
        matrix = nullptr;
        return;
    }
    file >> nRows;
    file >> nCols;
    nCols = nCols + 1;

    allocateMemory();

    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
            file >> matrix[i][j];
    }

    file.close();
}

// Set Values of matrix
void Matrix::setValues()
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}
// Memory Allocator function
void Matrix::allocateMemory()
{
    // array of pointers
    matrix = new long double *[nRows];

    // each pointer points to a row having nCols
    for (int i = 0; i < nRows; ++i)
    {
        matrix[i] = new long double[nCols];
    }
}

void Matrix::swapRows(int r,int index)
{
    long double *temp = matrix[r];
    matrix[r] = matrix[index];
    matrix[index] = temp;
}

// friend functions
ostream &operator<<(std::ostream &out, Matrix &M)
{
    for (int i = 0; i < M.getNRow(); ++i)
    {
        for (int j = 0; j < M.getNCol(); ++j)
            out << M.getValue(i, j) << " ";
        out << "\n";
    }
    return out;
}

// Destructor
Matrix::~Matrix()
{
    if (matrix)
    {
        for (int i = 0; i < nRows; i++)
            delete[] matrix[i];
    }
    delete[] matrix;
}
