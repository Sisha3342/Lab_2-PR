#pragma once
#include <vector>

class Matrix
{
	size_t rows_ = 0;
	size_t cols_ = 0;
	std::vector<std::vector<int>> matrix_;
public:

	Matrix(size_t rows, size_t cols);
	Matrix(Matrix const& M) = delete;
	Matrix(Matrix && M) = delete;

	Matrix operator*(Matrix const& M);
	bool operator==(Matrix const& M);
	bool operator!=(Matrix const& M);
};
