#include "matrix.h"

std::istream& operator>> (std::istream& in, matrix& M)
{
	for (int i = 0; i < M.rows; i++)
		for (int j = 0; j < M.columns; j++)
			in >> M.matr[i][j];

	return in;
}

std::ostream& operator<< (std::ostream& out, matrix const& M)
{
	for (int i = 0; i < M.rows; i++)
	{
		for (int j = 0; j < M.columns; j++)
			out << std::setw (4) << M.matr[i][j];
		out << std::endl;
	}



	return out;
}