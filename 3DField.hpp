#ifndef Field3D_h
#define Field3D_h 

#include<iostream>
#include<ostream>
#include<cassert>
#include<fstream>

//using namespace std;

const int dim = 3;

template <typename T>
class Grid3D
{
public:
    Grid3D();
    Grid3D(int m, int n, int l);
    Grid3D(const Grid3D & x);
    ~Grid3D();

    T** const operator[](int i);

    Grid3D<T> operator+(const Grid3D<T> & x) const;

    int nx() const { return _nx; }
    int ny() const { return _ny; }
    int nz() const { return _nz; }

    Grid3D<T> operator-(const Grid3D<T> & x) const;

    void operator=(const Grid3D<T> & x);

    // friend class can not be in .hpp
    friend std::ostream& operator<<(std::ostream& out, const Grid3D<T>& grid)
    {
        for(int i = 0; i < grid._nx; i++)
        {
            out <<  "------------- \n" ;
            for(int j = 0; j < grid._ny; j++)
            {
                out <<  "| " ;
                for(int k = 0; k < grid._nz; k++)
                {
                    out << grid._grid[i][j][k] << " " ;
                }
                out <<  "|\n" ;
            }
            out <<  "------------- "  << std::endl;
        }
        return out;
    }


private:
    int     _nx,_ny,_nz;
    T ***   _grid;
};


template <class T>
class Field3D
{
public:
    Field3D();
    Field3D(const Grid3D<T> & l_gried, double l_cell[3][3]);
    ~Field3D();
    bool isPeriodic();    // check if field is periodic
    double const ** cell() const ;
private:
    Grid3D<T>   _grid;
    double **   _cell;
};


class OField3D_cube
{
public:
    OField3D_cube(std::string l_name)
    {
    	_f.open(l_name.c_str());
    }

    friend void operator<<(OField3D_cube& out, const Field3D<double>& field)
    {
        _f << "Cell";
//        for(int i=1; i<dim; i++)
//       {
//            for(int j=1; j<dim; j++)
//            {
//                _f <<  field[i][j];
//            }
//            _f << std::endl;
//       }
//                if(_cell[i][j] != 0.0)
//                {
//                    is = true;
//                    break;
//                }    
//            }
//        }
//        return is;
//        for(int i = 0; i < field._nx; i++)
//        {
//            out <<  "------------- \n" ;
//            for(int j = 0; j < field._ny; j++)
//            {
//                out <<  "| " ;
//                for(int k = 0; k < field._nz; k++)
//                {
//                    out << field._grid[i][j][k] << " " ;
//                }
//                out <<  "|\n" ;
//            }
//            out <<  "------------- "  << std::endl;
//        }
//        return _f;
    }

//void write(const Field3D<double> & field)
//{
//	_f << "Tutaj będzie zapisany cube file ";
//}

//~OField3D_cube()
//{
//	_f.close();
//}

private:
std::ofstream _f;
};





#endif
