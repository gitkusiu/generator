#include "3DField.hpp"

template <typename T> Grid3D<T>::Grid3D()
    : _nx(0),_ny(0),_nz(0)
{}

template <typename T> Grid3D<T>::Grid3D(int m, int n, int l)
    : _nx(m), _ny(n), _nz(l)
{
    _field = new T**[_nx];
    for(int i=0; i<_nx; i++)
    {
        _field[i] = new T* [_ny];
        for(int j=0; j<_ny; j++)
        {
            _field[i][j] = new T [_nz];
        }
    }
}

template <typename T> Grid3D<T>::Grid3D(const Grid3D & x)   : _nx(x._nx),_ny(x._ny),_nz(x._nz)
{
    _field = new T**[_nx];
    for(int i=0; i<_nx; i++)
    {
        _field[i] = new T* [_ny];
        for(int j=0; j<_ny; j++)
        {
            _field[i][j] = new T [_nz];
            for(int k=0; k<_nz; k++)
            {
                _field[i][j][k] = x._field[i][j][k];
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
            delete[] _field[i][j]; 
        } 
        delete [] _field[i];
    }
    delete [] _field;
}

template <typename T> T** const Grid3D<T>::operator[](int i)
{
    return _field[i];
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
                tmp[i][j][k] += _field[i][j][k];
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
                tmp[i][j][k] -= _field[i][j][k];
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
                _field[i][j][k] = x._field[i][j][k];
            }
        }
    }
}

template class Grid3D<double>;




template <typename T> Field3D<T>::Field3D(const Grid3D<T> & l_gried) : _grid(2,3,4) {}

template class Field3D<double>;

