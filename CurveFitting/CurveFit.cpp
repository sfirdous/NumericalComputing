#include "CurveFit.hpp"
#include <iostream>
#include <fstream>

CurveFit::CurveFit()
{
    std::cout << "Pass number of datapoints as arguments" << std::endl;
    n = 0;
    x_i = nullptr;
    f_x_i = nullptr;
}

CurveFit::CurveFit(int n)
{
    this->n = n;
    allocateMemory();
}


CurveFit::CurveFit(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
            exit(1);
    }

    int n = 0;
    file >> n;
    allocateMemory();
    for (int i = 0; i < n; i++) {
            long double x, f_x;
            file >> x >> f_x;
            x_i[i] = x;
            f_x_i[i] = f_x;
    }

    file.close();
}

void CurveFit::allocateMemory()
{
    x_i = new long double[n];
    f_x_i = new long double[n];
}

CurveFit::~CurveFit()
{
    if(x_i && f_x_i)
    {
        delete[] x_i;
        delete[] f_x_i;
    }
    
}