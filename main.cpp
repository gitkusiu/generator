#include "3DField.hpp"

int main()
{

    const int dim = 3;
    double ** cell;
    cell = new double* [dim];
    for(int i=1; i<dim; i++)
    {
        cell[i] = new double [dim];
        for(int j=1; j<dim; j++)
        {
            cell[i][j] = double(i*j);
        }
    }
    int n,m,k;
    m=n=k=100;
    Grid3D<double> grid(m,n,k);
    std::cout << "KKK" << std::endl;
    Field3D<double> field(grid);
    std::cout << "KKK2" << std::endl;

    Field3DStreamer_cube stremer(field);
    std::cout << "KKK3" << std::endl;
    std::cout << stremer ;
}
