#include "pch.h"
#include "matrix.h"

Matrix::Matrix()
{
	rows_ = cols_ = 0;
}

Matrix Matrix::parallel_mult(Matrix const& m)
{
	if (cols_ != m.rows_)
		throw std::length_error("incorrect matrices sizes");

	std::vector<std::vector<int>> result(rows_, std::vector<int>(m.cols_));

	int threads_count = std::thread::hardware_concurrency();
	std::vector<std::thread> my_threads;
	my_threads.reserve(threads_count);

	int new_elements = rows_ * m.cols_, to_each_thread = new_elements / threads_count, left_count = new_elements % threads_count;

	for (int i = 0, j = 0; i < rows_;)
	{
		int temp = to_each_thread;
		if (left_count != 0)
		{
			temp++;
			left_count--;
		}

		my_threads.emplace_back(std::thread([i, j, temp, &result, this, &m]()
		{
			int l = j, t = temp;
			for (int k = i; t != 0; k++)
			{
				for (; t != 0 && l < m.cols_; l++)
				{
					for (int r = 0; r < cols_; r++)
						result[k][l] += matrix_[k][r] * m.matrix_[r][l];
					t--;
				}
				l = 0;
			}
		}));
		i += (j + temp) / m.cols_;
		j = (j + temp) % m.cols_;
	}

	for (int i = 0; i < my_threads.size(); i++)
		my_threads[i].join();

	return Matrix(result);
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

	std::vector<std::vector<int>> result(rows_, std::vector<int>(m.cols_));

	for (auto i = 0; i < rows_; i++)
		for (auto j = 0; j < m.cols_; j++)
			for (auto r = 0; r < cols_; r++)
				result[i][j] += matrix_[i][r] * m.matrix_[r][j];

	return Matrix(result);
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