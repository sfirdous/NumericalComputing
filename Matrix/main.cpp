#include <iostream>
#include "Matrix.hpp"
int main()
{
    // Matrix<int> m(2,2);
    // Matrix<int> n(m);

    // std::cout << m; 
    // std::cout << n;

    Matrix<double> p("double_49x50.txt");
    std::cout << p.getRow() << "\t" << p.getCol() << endl;  
    std::cout << p;
}