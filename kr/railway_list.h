#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <algorithm>

struct railway
{
	std::string start_city;
	tm start_date;
	std::string end_city;
	tm end_date;
	int tickets_left;
	int capacity;

	void get_info(std::string info);
	bool reserve_ticket();
	std::string take_full_string_info();
	friend std::ostream& operator<< (std::ostream& out, railway const& rail);
};

class railways_list
{
	std::vector<railway> list_;
	int railways_count;

public:

	railways_list() = default;
	railways_list(railways_list const&) = delete;
	railways_list(railways_list&&) = delete;
	railway& operator[](int index);

	friend std::ostream& operator<<(std::ostream& out, railways_list const& list1);
	friend std::istream& operator>>(std::istream& in, railways_list & list1);

	void sort_by_date();
};