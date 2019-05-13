#pragma once
#include <vector>

class Matrix
{
	int rows_ = 0;
	int cols_ = 0;
	std::vector<std::vector<int>> matrix_;
public:

	Matrix(int rows, int cols)
	{
		this->rows_ = rows;
		this->cols_ = cols;
	}

};
