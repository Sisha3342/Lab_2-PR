#include "concert_list.h"

int main()
{
	setlocale(LC_ALL, "rus");

	concert_list lisr2("list.txt");

	std::cout << lisr2;

	return 0;
}
