#include <iostream>
#include "railway_list.h"

int main()
{
	std::cout << 1;

	railways_list list1;

	std::fstream fin("rail_l.txt");

	while (!fin.eof())
	{
		fin >> list1;
	}

	std::cout << list1;

	fin.close();

	return 0;
}