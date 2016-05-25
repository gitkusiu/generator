
#include "3DField.hpp"

int main()
{
	int n,m,k;
	m=n=k=400;
	Grid3D<double> field(m,n,k);

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int jj=0; jj<k; jj++)
			{
				field[i][j][jj] = (double)(i+j+jj);
			}
		}
	}
//	std::cout << field;


//	std::cout << field[1][1][1];

	Grid3D<double> field2(m,n,k);
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int jj=0; jj<k; jj++)
			{
				field2[i][j][jj] = 1.0;
			}
		}
	}
	std::cout << "KK\n";
//	std::cout << field2;


//	Field3D<double> field3(field);
//	field[1][1][1] = 12.7
	Grid3D<double> x1=(field+field2);

	std::cout << "KK\n";
//	std::cout << x1;


	Grid3D<double> x2=(field-field);

	std::cout << "KK\n";
//	std::cout << x2;

	Field3D<double> f(x2);


	
//std::array<double, 2> a;
//a.fill(2.3,5.6);
//std::cout << a[2];
//std::array<std::array<double, 2> 2> a = { {1.0,2.0}, {3.0,4.0} };
}
