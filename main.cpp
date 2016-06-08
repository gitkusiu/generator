#include "3DField.hpp"

int main()
{
    int n,m,k;
    m=n=k=400;
    std::cout << "KKK0" << std::endl;
    Grid3D<double> grid(m,n,k);
    std::cout << "KKK" << std::endl;
    Field3D<double> field(grid);
    std::cout << "KKK2" << std::endl;
//    OField3D_cube out("dddd");
    
    Field3DStreamer_cube stremer(field);
    std::cout << "KKK3" << std::endl;
    std::cout << stremer ;
}
