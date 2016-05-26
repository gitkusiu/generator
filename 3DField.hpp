#ifndef Field3D_h
#define Field3D_h 

#include<iostream>
#include<ostream>
#include<cassert>
#include<fstream>

//using namespace std;

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
    friend std::ostream& operator<<(std::ostream& out, const Grid3D<T>& field)
    {
        for(int i = 0; i < field._nx; i++)
        {
            out <<  "------------- \n" ;
            for(int j = 0; j < field._ny; j++)
            {
                out <<  "| " ;
                for(int k = 0; k < field._nz; k++)
                {
                    out << field._field[i][j][k] << " " ;
                }
                out <<  "|\n" ;
            }
            out <<  "------------- "  << std::endl;
        }
        return out;
    }


private:
    int     _nx,_ny,_nz;
    T ***   _field;
};


template <class T>
class Field3D
{
public:
    Field3D(const Grid3D<T> & l_gried);
    
private:
    Grid3D<T>   _grid;
    double      _cell[3];
};


//class OField3D_cube
//{
//public:
//OField3D_cube(std::string l_name)
//{
//	_f.open(l_name.c_str());
//}

//void write(const Field3D<double> & field)
//{
//	_f << "Tutaj będzie zapisany cube file ";
//}

//~OField3D_cube()
//{
//	_f.close();
//}

//private:
//std::ofstream _f;
//};





#endif
