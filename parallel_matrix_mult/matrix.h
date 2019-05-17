#pragma once
#include <vector>
#include <thread>

class Matrix
{
	size_t rows_ = 0;
	size_t cols_ = 0;
	std::vector<std::vector<int>> matrix_;
public:
	Matrix();
	Matrix(size_t rows, size_t cols);
	Matrix(std::vector<std::vector<int>> matrix);
	Matrix(Matrix const& M) = delete;
	Matrix(Matrix && M);

	Matrix operator*(Matrix const& m);
	Matrix parallel_mult(Matrix const& m, int threads_count);
	friend bool operator==(Matrix const& m1, Matrix const& m2);
	friend bool operator!=(Matrix const& m1, Matrix const& m2);
	Matrix& operator=(Matrix const& m);
};
