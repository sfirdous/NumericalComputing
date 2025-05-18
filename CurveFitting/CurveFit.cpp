#include "CurveFit.hpp"

CurveFit::CurveFit(int size)
{
    n = size;
    x = std::vector<double>(n);
    fx = std::vector<double>(n);
}

CurveFit::CurveFit(std::string filename)
{
    std::ifstream file(filename);

    if (!file)
    {
        n = 0;
        return;
    }

    file >> n;
    x = std::vector<double>(n);
    fx = std::vector<double>(n);
    for(int i = 0 ; i < n ; ++i)
        file >> x[i] >> fx[i];
    
    file.close();
}

CurveFit::CurveFit(const CurveFit &other){
 n = other.n;
 x = other.x;
 fx = other.fx;
}
