#include "pch.h"
#include "matrix.h"

Matrix::Matrix()
{
	rows_ = cols_ = 0;
}

Matrix::Matrix(Matrix&& m)
{
	rows_ = m.rows_;
	cols_ = m.cols_;
	matrix_ = m.matrix_;
}

Matrix::Matrix(size_t rows, size_t cols)
{
	rows_ = rows;
	cols_ = cols;
	matrix_ = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
}

Matrix::Matrix(std::vector<std::vector<int>> matrix)
{
	matrix_ = matrix;
	rows_ = matrix.size();
	cols_ = matrix[0].size();
}

Matrix Matrix::operator*(Matrix const& m)
{
	if (cols_ != m.rows_)
		throw std::length_error("incorrect matrices sizes");

	std::vector<std::vector<int>> temp_matrix(rows_, std::vector<int>(m.cols_));

	for (auto i = 0; i < rows_; i++)
		for (auto j = 0; j < m.cols_; j++)
			for (auto r = 0; r < cols_; r++)
				temp_matrix[i][j] += matrix_[i][r] * m.matrix_[r][j];

	return Matrix(temp_matrix);
}

bool operator==(Matrix const& m1, Matrix const& m2)
{
	return !(m1.cols_ != m2.cols_ || m1.rows_ != m2.rows_ || m1.matrix_ != m2.matrix_);
}

bool operator!=(Matrix const& m1, Matrix const& m2)
{
	return !(m1 == m2);
}

Matrix& Matrix::operator=(Matrix const& m)
{
	if (this == &m)
		return *this;

	matrix_ = m.matrix_;
	cols_ = m.cols_;
	rows_ = m.rows_;

	return *this;
}