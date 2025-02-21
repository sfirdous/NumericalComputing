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
    allocateMemory();

}

//Copy Constructor
template <typename T>
Matrix<T>::Matrix(const Matrix<T> &other)
{
    setRow(other.getRow());
    setCol(other.getCol());
    allocateMemory();

    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            this->matrix[i][j] = other.matrix[i][j];
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
        return;
    }
    else
    {
        file >> nRows;
        file >> nCols;

        allocateMemory();

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
    matrix = nullptr;
}

template <typename T>
Matrix<T> Matrix<T>::add(const Matrix<T>& B) const
{
   Matrix<T> result(nRows,nCols);

   for (int i = 0; i < nRows; i++)
   {
    for (int j = 0; i < nCols; j++)
    {
        result.matrix[i][j] = this->matrix[i][j] + B.getValue(i,j);
    }
   }

   return result;
   
}

template <typename T>
Matrix<T> Matrix<T>::sub(const Matrix<T>& B) const
{
    Matrix<T> result(nRows,nCols);

    for (int i = 0; i < nRows; i++)
    {
     for (int j = 0; j < nCols; j++)
     {
         result.matrix[i][j] = this->matrix[i][j] - B.getValue(i,j);
     }
    }
 
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::mul(const Matrix<T>& B) const
{
    Matrix<T> result(this->nCols,B.getRow());

    for(int i = 0 ; i < this->nRows ; ++i)
    {
        for(int j = 0 ; j < B.getCol() ; ++j)
        {
            result.matrix[i][j] = 0;
            for (int k = 0; k < this->nCols; k++)
            {
                result.matrix[i][j] += this->matrix[i][k] * B.getValue(k,j);
            }
            
        }
    }

    return result;
}


template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& B) const
{
    return this->add(B);
}

template <typename T> 
Matrix<T> Matrix<T>::operator-(const Matrix<T>& B) const
{
    return this->sub(B);
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& B) const
{
   return this->mul(B);
}


template <typename T>
std::ostream &operator<<(std::ostream &os, Matrix<T> &m)
{
    for (int i = 0; i < m.getRow(); ++i)
    {
        for (int j = 0; j < m.getCol(); ++j)
        {
            os << m.getValue(i, j) << "\t";
        }
        os << "\n";
    }
    return os;
}

template <typename T>
bool Matrix<T>::isIdentity(Matrix<T>& A)
{
    int rows = A.getRow();
    int cols = A.getCol();

    if(rows != cols)
        return false;
    for(int i = 0 ; i < rows ;++i)
    {
        for(int j = 0; j < cols;++j)
        {
            T value = A.getValue(i,j);
            if(i == j && value != 1)
                return false;
            else if(i != j && value != 0)
                return false;
        }
    }

    return true;
}

template <typename T>
bool Matrix<T>::isSymmetric(Matrix<T>& A)
{
    int rows = A.getRow();
    int cols = A.getCol();

    if(rows != cols)
        return false;
    for(int i = 0 ; i < rows ;++i)
    {
        for(int j = i+1; j < cols;++j)
        {
            
            if(A.getValue(i,j) != A.getValue(j,i))
                return false;
        }
    }

    return true;
}

template <typename T>
void Matrix<T>::setValues()
{
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::allocateMemory()
{
   
    // Allocate meomery for row pointers
    this->matrix = new T *[nRows];

    // Allocate meomery for column in each row
    for (int i = 0; i < nRows; ++i)
    {
        this->matrix[i] = new T[nCols];
    }
}

// Explicit Instantiation (for int and double matrices)
template class Matrix<int>;
template class Matrix<double>;