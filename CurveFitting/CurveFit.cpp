#include "CurveFit.hpp"
#include <iostream>
#include <fstream>

// Default Constructor
CurveFit::CurveFit() {
    n = 0;
    x_i = nullptr;
    f_x_i = nullptr;
}

CurveFit::CurveFit(int n)
{
    this->n = n;
    allocateMemory();
}


CurveFit::CurveFit(string filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file.\n";
        exit(1);
    }

    file >> n;
    allocateMemory();

    for (int i = 0; i < n; i++) {
        file >> x_i[i] >> f_x_i[i];
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
