#include "matrix.h"

int main()
{
	matrix A(2, 2);

	std::cin >> A;

	matrix B(2, 3);
	std::cin >> B;

	matrix C(1, 1);

	C = A * B;

	std::cout << C;

	return 0;
}