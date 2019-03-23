#pragma once
#include <iostream>
#include <iomanip>

class matrix
{
	double **matr;
	int columns;
	int rows;
public:
	matrix()
	{
		columns = rows = 0;
		matr = nullptr;
	}

	matrix(int row, int col)
	{
		columns = col;
		rows = row;

		matr = new double*[rows];
		for (int i = 0; i < rows; i++)
			matr[i] = new double[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				matr[i][j] = 0;
	}
	
	matrix(matrix const& M)
	{
		columns = M.columns;
		rows = M.rows;

		matr = new double*[rows];
		for (int i = 0; i < rows; i++)
			matr[i] = new double[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				matr[i][j] = M.matr[i][j];
		
	}

	matrix(matrix && M)
	{
		columns = M.columns;
		rows = M.rows;
		matr = M.matr;
		M.matr = nullptr;
	}

	virtual ~matrix()
	{
		for (int i = 0; i < rows; i++)
			delete[] matr[i];
		delete[] matr;
	}

	matrix& operator= (matrix const& M);
	matrix& operator+= (matrix const& M);
	matrix& operator-= (matrix const& M);
	matrix operator+ (matrix const& M);
	matrix operator- (matrix const& M);
	matrix& operator*= (matrix const& M);
	matrix& operator*= (double value);
	matrix operator* (matrix const& M);
	matrix operator* (double value);
	matrix operator- ();
	matrix without_irow_jcol(int del_i, int del_j);
	double Determinant();
	friend std::istream& operator>> (std::istream& in, matrix& M);
	friend std::ostream& operator<< (std::ostream& out, matrix const& M);
};
