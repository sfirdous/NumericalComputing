#include <iostream>
#include "Matrix.hpp"
int main()
{
    // Matrix<int> m(2,2);
    // Matrix<int> n(m);

    // std::cout << m; 
    // std::cout << n;

    Matrix<double> p("Matrix/matrices/double_49x50.txt");
    std::cout << p.getRow() << "\t" << p.getCol() << std::endl;  
    std::cout << p;
}