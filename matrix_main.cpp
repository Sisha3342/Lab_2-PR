#include "matrix.h"

int main()
{
	matrix A(1, 2);

	std::cin >> A;
	matrix B(1, 2);
	std::cin >> B;

	A -= B;

	std::cout << B;

	return 0;
}