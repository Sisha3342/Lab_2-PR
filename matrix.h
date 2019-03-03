#pragma once
#include <iostream>
#include <iomanip>

class matrix
{
	int **matr;
	int columns;
	int rows;
public:
	matrix(int row, int col)
	{
		columns = col;
		rows = row;

		matr = new int*[rows];
		for (int i = 0; i < rows; i++)
			matr[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				matr[i][j] = 0;
	}
	
	matrix(matrix const& M)
	{
		columns = M.columns;
		rows = M.rows;

		matr = new int*[rows];
		for (int i = 0; i < rows; i++)
			matr[i] = new int[columns];

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
	/*friend matrix operator- (matrix const& M);*/
	friend std::istream& operator>> (std::istream& in, matrix& M);
	friend std::ostream& operator<< (std::ostream& out, matrix const& M);
};