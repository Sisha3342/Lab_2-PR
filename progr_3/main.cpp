#include "concert_list.h"

int main()
{
	setlocale(LC_ALL, "rus");

	
	concert_list list_1;

	std::fstream fin1("lul1.txt");

	while (!fin1.eof())
	{
		fin1 >> list_1;
	}

	std::cout << list_1;

	list_1.sort_by_name();

	fin1.clear();
	fin1.seekg(0, std::ios::beg);

	fin1 << list_1;
	fin1.close();

	return 0;
}