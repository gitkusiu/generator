#include "3DField.hpp"





template <typename T> Grid3D<T>::Grid3D()
    : _nx(1),_ny(1),_nz(1)
{
    _grid[0][0][0] = T();
}

template <typename T> Grid3D<T>::Grid3D(int m, int n, int l)
    : _nx(m), _ny(n), _nz(l)
{
    _grid = new T**[_nx];
    for(int i=0; i<_nx; i++)
    {
        _grid[i] = new T* [_ny];
        for(int j=0; j<_ny; j++)
        {
            _grid[i][j] = new T [_nz];
        }
    }
}

template <typename T> Grid3D<T>::Grid3D(const Grid3D & x)   : _nx(x._nx),_ny(x._ny),_nz(x._nz)
{
    _grid = new T**[_nx];
    for(int i=0; i<_nx; i++)
    {
        _grid[i] = new T* [_ny];
        for(int j=0; j<_ny; j++)
        {
            _grid[i][j] = new T [_nz];
            for(int k=0; k<_nz; k++)
            {
                _grid[i][j][k] = x._grid[i][j][k];
            }
        }
    }
}

template <typename T> Grid3D<T>::~Grid3D()
{
    for(int i=_nx-1; i>=0; i--)
    {
        for(int j=_ny-1; j>= 0; j--)
        {
            delete[] _grid[i][j]; 
        } 
        delete [] _grid[i];
    }
    delete [] _grid;
}

template <typename T> T** const Grid3D<T>::operator[](int i)
{
    return _grid[i];
}

template <typename T> Grid3D<T> Grid3D<T>::operator+(const Grid3D<T> & x) const
{
    assert(x._nx==_nx  && x._ny==_ny && x._nz==_nz);
    Grid3D<T> tmp(x);

    for(int i=_nx-1; i>=0; i--)
    {
        for(int j=_ny-1; j>= 0; j--)
        {
            for(int k=_nz-1; k>= 0; k--)
            {
                tmp[i][j][k] += _grid[i][j][k];
            }
        }
    }
    return tmp;
}

template <typename T> Grid3D<T> Grid3D<T>::operator-(const Grid3D<T> & x) const
{
    assert(x._nx==_nx  && x._ny==_ny && x._nz==_nz);
    Grid3D<T> tmp(x);

    for(int i=_nx-1; i>=0; i--)
    {
        for(int j=_ny-1; j>= 0; j--)
        {
            for(int k=_nz-1; k>= 0; k--)
            {
                tmp[i][j][k] -= _grid[i][j][k];
            }
        }
    }
    return tmp;
}

template <typename T> void Grid3D<T>::operator=(const Grid3D<T> & x)
{
    assert(x._nx==_nx  && x._ny==_ny && x._nz==_nz);
    for(int i=_nx-1; i>=0; i--)
    {
        for(int j=_ny-1; j>= 0; j--)
        {
            for(int k=_nz-1; j>= 0; j--)
            {
                _grid[i][j][k] = x._grid[i][j][k];
            }
        }
    }
}

template class Grid3D<double>;



template <typename T> Field3D<T>::Field3D()
	: _grid()
{
    for(int i=1; i<3; i++)
    {
        for(int j=1; j<3; j++)
        {
           _cell[i][j] = 0.0;
        }
    }
}


//template <typename T> Field3D<T>::Field3D(Grid3D<T> const & l_gried)
//	: _grid(l_gried) {}


template <typename T> Field3D<T>::Field3D(Grid3D<T> const & l_gried)
	: _grid(l_gried)
{
    const int dim = 3;
    _cell = new double* [dim];
    for(int i=1; i<dim; i++)
    {
        _cell[i] = new double [dim];
        for(int j=1; j<dim; j++)
        {
//           _cell[i][j] = l_cell[i][j];
        }
    }
}


template <typename T> Field3D<T>::~Field3D()
{
    const int dim = 3;
    for(int i=1; i<dim; i++)
    {
        delete _cell[i];
    }
    delete _cell;
}

template <typename T> bool Field3D<T>::isPeriodic()
{
    bool is = false;
    for(int i=1; i<dim; i++)
    {
        for(int j=1; j<dim; j++)
        {
            if(_cell[i][j] != 0.0)
            {
                is = true;
                break;
            }    
        }
    }
    return is;
}

template <typename T> double const ** Field3D<T>::cell() const
{
    
}

template class Field3D<double>;

