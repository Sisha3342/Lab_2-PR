#include "matrix.h"

matrix& matrix::operator= (matrix const& M)
{
	if (this == &M)
		return *this;

	for (int i = 0; i < rows; i++)
		delete[] matr[i];
	delete[] matr;

	rows = M.rows;
	columns = M.columns;
	matr = new double*[rows];
	for (int i = 0; i < rows; i++)
		matr[i] = new double[columns];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matr[i][j] = M.matr[i][j];

	return *this;
}

matrix& matrix::operator+= ( matrix const& M)
{
	if (rows != M.rows || columns != M.columns)
		throw "Incorrect matrices sizes! To add one matrix to another, their sizes must be the same!";
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matr[i][j] += M.matr[i][j];
	return *this;
}

matrix& matrix::operator-= (matrix const& M)
{
	if (rows != M.rows || columns != M.columns)
		throw "Incorrect matrices sizes! To sub one matrix from another, their sizes must be the same!";
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matr[i][j] -= M.matr[i][j];
	return *this;
}

matrix matrix::operator+ (matrix const& M)
{
	return matrix(*this) += M;
}

matrix matrix::operator- (matrix const& M)
{
	return matrix(*this) -= M;
}

matrix& matrix::operator*= (matrix const& M)
{
	matrix C(rows, M.columns);

	if (columns != M.rows)
		throw "Incorrect matrices sizes! To multiply matrices the amount of columns of the first and the amount of rows of the second must be the same!";
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < M.columns; j++)
			for (int r = 0; r < columns; r++)
				C.matr[i][j] += matr[i][r] * M.matr[r][j];
	*this = C;
	return *this;
}

matrix& matrix::operator*= (double value)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matr[i][j] *= value;
	return *this;
}

matrix matrix::operator* (matrix const& M)
{
	return matrix(*this) *= M;
}

matrix matrix::operator* (double value)
{
	return (*this *= value);
}

matrix matrix::operator- ()
{
	return (*this *= -1);
}

matrix matrix::without_irow_jcol(int del_i, int del_j)
{
	std::unique_ptr<matrix> p1(new matrix(rows - 1, columns - 1));

	for (int i = 0, i1 = 0; i1 < p1->rows; i++, i1++)
	{
		if (i == del_i)
		{
			i++;
		}

		for (int j = 0, j1 = 0; j1 < p1->columns; j++, j1++)
		{
			if (j == del_j)
			{
				j++;
			}
			p1->matr[i1][j1] = matr[i][j];
		}
	}

	return *p1;
}

double matrix::Determinant()
{
	if (rows != columns)
		throw "To find the determinant, matrix must be square";


	double det = 0;

	if (rows == 2 && columns == 2)
	{
		det += matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
	}
	else
	{
		for (int i = 0; i < columns; i++)
		{
			matrix help_matr = (*this).without_irow_jcol(0, i);
			if (i % 2 == 0)
				det += matr[0][i] * help_matr.Determinant();
			else
				det -= matr[0][i] * help_matr.Determinant();
		}
	}

	return det;
}

std::istream& operator>> (std::istream& in, matrix& M)
{
	for (int i = 0; i < M.rows; i++)
		for (int j = 0; j < M.columns; j++)
		{
			std::cout << "Input [" << i << "][" << j << "] element: ";
			in >> M.matr[i][j];
		}

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