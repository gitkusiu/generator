#ifndef Field3D_h
#define Field3D_h 

#include<iostream>
//#include<ostream>
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
//    Field3D(const Grid3D<T> & l_gried, double l_cell[3][3]);
    Field3D(Grid3D<T> const & l_gried);
    ~Field3D();
    bool isPeriodic();    // check if field is periodic
    double const ** cell() const ;
    int nx() const { return _grid.nx();}
    int ny() const { return _grid.ny();}
    int nz() const { return _grid.nz();}
private:
    Grid3D<T>   _grid;
    double **   _cell;
};



class Field3DStreamer
{
public:
Field3DStreamer(Field3D<double> & f) :_field(f) {}

protected:
//private:
Field3D<double> & _field;
};


class Field3DStreamer_cube : public Field3DStreamer
{
public:
Field3DStreamer_cube(Field3D<double> & f) : Field3DStreamer(f) {}

    friend std::ofstream & operator<<(std::ofstream & o, Field3DStreamer_cube const & f)
    {
        o << "comment 1";
        o << "comment 2";
        o << "0 0.0 0.0 0.0";
        o << f._field.nx() ;
        return o;
    }

    friend std::ostream & operator<<(std::ostream & o, Field3DStreamer_cube const & f)
    {
        o << "Halo Halo";
        return o;
    }
};

//std::ofstream & operator<<(std::ofstream & o, Field3D<double> & f)
//    {
//        o << "comment 1";
//        o << "comment 2";
//        o << "0 0.0 0.0 0.0";
//        o << f.nx() ;
//        return o;
//    }


#endif
