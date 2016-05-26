#ifndef Field3D_h
#define Field3D_h 

#include<iostream>
#include<ostream>
#include<cassert>
#include<fstream>

//using namespace std;

template <class T>
class Grid3D
{
public:
Grid3D(int m, int n, int l)
	:_nx(m),_ny(n),_nz(l)
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

//Grid3D()
//	:_nx(0),_ny(0),_nz(0)
//{
//}


Grid3D(const Grid3D & x)
	:_nx(x._nx),_ny(x._ny),_nz(x._nz)
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


~Grid3D()
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


T** const operator[](int i)
{
	return _field[i];
}

Grid3D<T> operator+(const Grid3D<T> & x) const
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


int nx() const { return _nx; }
int ny() const { return _ny; }
int nz() const { return _nz; }

Grid3D<T> operator-(const Grid3D<T> & x) const
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


void operator=(const Grid3D<T> & x)
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


friend std::ostream& operator<<(std::ostream& out, const Grid3D<T>& field) // output
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
//    out << "(" << vec.x() << ", " << vec.y() << ")";
    return out;
}


private:
int      _nx,_ny,_nz;
T ***    _field;
};


template <class T>
class Field3D
{
public:
Field3D(const Grid3D<T> & l_gried)
	: _grid(2,3,4)
{
}



private:
Grid3D<T>	_grid;
double      _cell[3];
};


class OField3D_cube
{
public:
OField3D_cube(std::string l_name)
{
	_f.open(l_name.c_str());
}

void write(const Field3D<double> & field)
{
	_f << "Tutaj będzie zapisany cube file ";
}

~OField3D_cube()
{
	_f.close();
}

private:
std::ofstream _f;
};





#endif
