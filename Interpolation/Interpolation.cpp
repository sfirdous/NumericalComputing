#include "Interpolation.hpp"

Interpolation::Interpolation(int size)
{
    n = size;
    x = std::vector<double>(n);
    fx = std::vector<double>(n);
}

Interpolation::Interpolation(std::string filename)
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

Interpolation::Interpolation(const Interpolation &other){
 n = other.n;
 x = other.x;
 fx = other.fx;
}
