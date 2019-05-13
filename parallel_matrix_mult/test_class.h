#pragma once
#include <vector>

class matrix_mult_test
{
	std::vector<int> matrix1;
	std::vector<int> matrix2;
public:
	matrix_mult_test(std::vector<int> matrix1, std::vector<int> matrix2);
	matrix_mult_test(matrix_mult_test const& T) = delete;
	matrix_mult_test(matrix_mult_test && T) = delete;

	std::vector<int> take_result();
};
