#include "matrix.h"

int main()
{
	matrix A(1, 2);

	std::cin >> A;

	matrix C(1, 2);

	C = A + A - A;

	std::cout << C;

	return 0;
}