#pragma once
#include <iostream>
#include <fstream>
#define MAX_LENGTH 128

struct concert
{
	char name[MAX_LENGTH];
	int tickets_left;
	int capacity;
	char date[MAX_LENGTH];
};

class concert_list
{
	concert *list;
	int concerts_count;
public:
	concert_list()
	{
		concerts_count = 0;
		list = nullptr;
	}
	concert_list(const char* file_path)
	{
		concerts_count = 0;
		std::ifstream fin1(file_path);
		if (!fin1.is_open())
			throw "Error! Can't open the file";

		char temp[MAX_LENGTH];
		int index = 0;

		while (fin1.getline(temp, MAX_LENGTH))
			concerts_count++;
		list = new concert[concerts_count];

		fin1.clear();
		fin1.seekg(0, std::ios::beg);

		while(fin1.getline(temp, MAX_LENGTH))
		{
			char *div, *div1, *p = strtok_s(temp, ";", &div);
			strcpy_s(list[index].name, MAX_LENGTH, p);
			p = strtok_s(0, ";", &div);
			list[index].tickets_left = strtol(p, &div1, 10);
			p = strtok_s(0, ";", &div);
			list[index].capacity = strtol(p, &div1, 10);
			p = strtok_s(0, ";", &div);
			strcpy_s(list[index].date, MAX_LENGTH, p);

			index++;
		}

		fin1.close();
	}

	concert_list(concert_list const& list1)
	{
		concerts_count = list1.concerts_count;

		list = new concert[concerts_count];

		for (int i = 0; i < concerts_count; i++)
		{
			strcpy_s(list[i].name, MAX_LENGTH, list1.list[i].name);
			list[i].tickets_left = list1.list[i].tickets_left;
			list[i].capacity = list1.list[i].capacity;
			strcpy_s(list[i].date, MAX_LENGTH, list1.list[i].date);
		}
	}

	concert_list(concert_list && list1)
	{
		concerts_count = list1.concerts_count;
		list = list1.list;
	}

	virtual ~concert_list()
	{
		delete[] list;
	}

	void append(concert const& conc);
	int get_concerts_count();
	concert& operator[](int index);

	friend std::ostream& operator<< (std::ostream& out, concert_list const& list1);
	friend std::istream& operator>> (std::istream& in, concert_list& list1);
};