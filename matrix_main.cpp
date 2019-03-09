#include "matrix.h"

int main()
{
	matrix A(3, 3);
//	matrix B(3, 3);

	std::cin >> A;
//	std::cin >> B;

	try
	{
		/*matrix C = A + B;
		std::cout << C;

		matrix D = A - B;
		std::cout << D;

		matrix E = A * B;
		std::cout << E;
*/
		std::cout << A.Determinant();
	}
	catch(const char* ex)
	{
		std::cout << ex;
		return 1;
	}

	return 0;
}