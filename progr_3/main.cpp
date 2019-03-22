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

	

	if (list_1.find_first_date_between(list_1[0].date, list_1[1].date) != list_1.end())
	{
		std::cout << *(list_1.find_first_date_between(list_1[0].date, list_1[1].date));
	}

	fin1.clear();
	fin1.seekg(0, std::ios::beg);

	fin1 << list_1;
	fin1.close();

	return 0;
}