#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <boost/algorithm/string.hpp>
#define MAX_SIZE 50

struct concert
{
	std::string name;
	int tickets_left{};
	int capacity{};
	tm date{};

	void get_info(std::string info);
	void reserve();
	friend std::ostream& operator<< (std::ostream& out, concert const& conc);
};

class concert_list
{
	std::vector<concert> list_;
public:

	concert_list() = default;
	concert_list(concert_list const&) = delete;
	concert_list(concert_list&&) = delete;

	/*concert_list(concert_list const& list1)
	{
		list = list1.list;
	}

	concert_list(concert_list && list1) noexcept
	{
		list = list1.list;
	}*/

	int get_concerts_count() const;
	concert& operator[](int index);
	void reserve_ticket(int conc_index);
	void sort_by_name();
	void sort_by_date();

	friend std::ostream& operator<< (std::ostream& out, concert_list const& list1);
	friend std::istream& operator>> (std::istream& in, concert_list& list1);
};