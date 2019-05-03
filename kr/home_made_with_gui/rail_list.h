#pragma once
#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <msclr/marshal_cppstd.h>

struct railway
{
	std::string start_city;
	tm start_date;
	std::string end_city;
	tm end_date;
	int tickets_left;
	int capacity;

	railway() = default;
	railway(std::string info);
	bool reserve_ticket();
	std::string take_full_string_info() const;
	friend std::ostream& operator<< (std::ostream& out, railway const& rail);
};

class railways_list
{
	std::vector<railway> list_;

public:

	railways_list() = default;
	railways_list(railways_list const&) = delete;
	railways_list(railways_list&&) = delete;
	railway& operator[](size_t index);
	void add_railway(railway const&);
	int get_railways_count();

	friend std::ostream& operator<<(std::ostream& out, railways_list const& list1);
	friend std::istream& operator>>(std::istream& in, railways_list & list1);

	railways_list& operator=(railways_list const&);

	void sort_by_start_date();
};

std::string correct_date(tm to_convert_date);
std::string correct_time(tm to_convert_date);